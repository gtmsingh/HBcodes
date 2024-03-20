# Packages required: pillow==10.2.0 ffmpeg-python==0.2.0  
import json
import ffmpeg
import itertools
from PIL import Image
from PIL import ExifTags
from datetime import datetime
from pathlib import Path
from pprint import pprint

DT_TIME_FORMAT = "%Y:%m:%d %H:%M:%S"
VIDEO_DT_TIME_FORMAT = "%Y-%m-%dT%H:%M:%S.%fZ"
OUTPUT_DT_TIME_FORMAT = "%Y-%m-%d %H_%M_%S"
HOME_PATH = Path(__file__).parent.parent

mediaFiles = itertools.chain(
    HOME_PATH.glob("*.jpg"),
    HOME_PATH.glob("*.JPG"),
    HOME_PATH.glob("*.mp4"),
    HOME_PATH.glob("*.MP4"),
)


def get_date_from_video(filename):
    metadata = [
        info
        for info in ffmpeg.probe(filename)["streams"]
        if info["codec_type"] == "video"
    ][0]
    pprint(ffmpeg.probe(filename)["streams"])

    videoDt = metadata.get("tags", {}).get("creation_time")
    if videoDt is None:
        raise Exception(f"Datetime not found. Metadata: {json.dumps(metadata)}")

    return datetime.strptime(videoDt, VIDEO_DT_TIME_FORMAT)


def get_date_from_image(filename):
    # open the image
    image = Image.open(filename)

    metaMap = {
        ExifTags.TAGS[k]: v for k, v in image._getexif().items() if k in ExifTags.TAGS
    }
    # pprint(metaMap)
    imageDt = metaMap.get("DateTimeOriginal") or metaMap.get("DateTime") 
    if imageDt is None:
        raise Exception(f"Datetime not found. Metadata: {json.dumps(metaMap)}")

    return datetime.strptime(imageDt, DT_TIME_FORMAT)


for file in mediaFiles:
    if file.name.startswith("BaliTrip - "):
        continue

    print(f"Reading file: {file}", end=" ")
    try:
        filename = file.absolute().as_posix()
        if filename.lower().endswith(".mp4"):
            dt = get_date_from_video(filename)
        elif filename.lower().endswith(".jpg"):
            dt = get_date_from_image(filename)
        else:
            raise Exception(f"Unknown file name found")

        print(f"Date: {dt}")
        # file.rename(
        #     f"BaliTrip - {dt.strftime(OUTPUT_DT_TIME_FORMAT)} ({file.stem}){file.suffix.lower()}"
        # )
    except Exception as err:
        print(f"Something wrong happened with file '{file}': {err}")

# file = Path('./BaliTrip - 2024-03-01 07_36_41 (GX010036_1709375312705).mp4')
# print(get_date_from_video(file))
