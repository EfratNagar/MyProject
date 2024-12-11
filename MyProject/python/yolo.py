import sys

import torch
from PIL import Image
import matplotlib.pyplot as plt

# טען את דגם ה-YOLOv5
model = torch.hub.load('ultralytics/yolov5', 'yolov5s')

# אתחל את נקודת הקובץ כדי לעקוב אחר המיקום הנוכחי
file_pointer = 0


def process_next_image():
    # global file_pointer
    #
    # with open('image_paths.txt', 'r', encoding='utf-8') as file:
    #     # קרא את השורות של הקובץ
    #     lines = file.readlines()
    #
    #     # בדוק אם יש עוד שורות לעיבוד
    #     if file_pointer < len(lines):
            # קבל את נתיב התמונה מהשורה הבאה
    img_path = sys.argv[1]
    #img_path = "IMG_3268.JPG"

    #img_path = lines[file_pointer].strip()
    if img_path:
        img = Image.open(img_path)
        # טען את התמונה

        # בצע חיזוי על התמונה
        results = model(img)

        # קבל את התוויות ואת תיבות הגבול של האובייקטים שנמצאו
        labels = results.names
        boxes = results.xyxy[0]

        # סנן רק את האובייקטים מסוג 'אדם'
        people_boxes = [box for box in boxes if labels[int(box[5])] == 'person']

        # ספור את מספר האנשים שנזהו
        num_people = len(people_boxes)
        # שמור את מספר האנשים לקובץ טקסט
        # with open('people_count.txt', 'w') as count_file:
        #     count_file.write(f"{int(num_people)}\n")

        # print(num_people)
    else:
        num_people = 0
        print("Empty line: No image path provided.")

            # העבר את נקודת הקובץ לשורה הבאה לשיחות הבאות
            # file_pointer += 1
        # else:
        #  print("No more images to process.")
    return num_people

# קרא את הפונקציה לעיבוד התמונה הבאה

#for p in identified_images_array:
os=process_next_image()
print(int(''.join(str(os))))
# print(" ".join(str(os)))
# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print('PyCharm')