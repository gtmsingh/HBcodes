# Before running the script, run `pip install Pillow`

import os
import glob
from PIL import Image
# from PIL.ExifTags import TAGS
from datetime import datetime
from pathlib import Path
import subprocess


# print(TAGS[306], TAGS[36867])
for file in glob.glob('*.jpg'):
    imageDt = (Image.open(file)._getexif() or {}).get(36867)
    if imageDt is None:
        continue
    folder = datetime.strptime(imageDt, '%Y:%m:%d %H:%M:%S').strftime('%Y-%m')
    print(file, imageDt, folder)
    Path(f'./{folder}').mkdir(exist_ok=True)
    os.rename(file, f'{folder}/{file}')

for file in glob.glob('*.mp4'):
    cmnd = ['ffprobe', '-show_format', '-pretty', '-loglevel', 'quiet', file]
    p = subprocess.Popen(cmnd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    out, err =  p.communicate()
    if err:
        print(err)
        continue
    print(file)
    for line in out.decode('UTF-8').split('\n'):
        if not line.startswith('TAG:creation_time'):
            continue
        print(line)
        dt = datetime.fromisoformat(line.split('=')[1].strip('Z'))
        folder = dt.strftime('%Y-%m')
        Path(folder).mkdir(exist_ok=True)
        os.rename(file, f'{folder}/{file}')
    # break
