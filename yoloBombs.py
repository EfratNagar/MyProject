# import torch
#
# # Load the model
# model = torch.hub.load('ultralytics/yolov5', 'custom', path='C:/Users/WIN 11/Desktop/yolov5-master/runs/train/model8/weights/best.pt')
#
# from PIL import Image
#
# # Load an image
# img = Image.open('C:/Users/WIN 11/Desktop/פרוייקט מנהרות/Bombs/800px-Mines_501556_fh000026.jpg')
#
# # Perform inference
# results = model(img)
#
# # Display the results
# results.show()
#
# from inference_sdk import InferenceHTTPClient
#
# CLIENT = InferenceHTTPClient(
#     api_url="https://outline.roboflow.com",
#     api_key="8HucnSVHlbXiHvmXgk6P"
# )
#
# result = CLIENT.infer('C:/Users/WIN 11/Desktop/פרוייקט מנהרות/Bombs/800px-Mines_501556_fh000026.jpg', model_id="iedcolor/1")
#
# import torch
# from PIL import Image
# import os
# from glob import glob

# # Load the trained model
# model = torch.hub.load('ultralytics/yolov5', 'custom', path='C:/Users/WIN 11/Desktop/yolov5-master/runs/train/model8/weights/best.pt')
#
#
# # Set model to evaluation mode
# model.eval()
#
# # Define the folder path containing the images
# folder_path = 'C:/Users/WIN 11/Desktop/פרוייקט מנהרות/Bombs'
#
# # Get a list of image file paths in the folder
# image_paths = glob(os.path.join(folder_path, '*.jpg')) + glob(os.path.join(folder_path, '*.png'))
#
# # Function to perform object detection on an image
# def detect_objects(image_path):
#     img = Image.open(image_path)
#     results = model(img)  # Perform object detection
#     return results.pandas().xyxy[0]  # Return detected objects in the image
#
# # Iterate through each image in the folder and perform object detection
# for image_path in image_paths:
#     detected_objects = detect_objects(image_path)
#     if detected_objects is not None:
#         print(f'Objects detected in {image_path}: {detected_objects["name"].tolist()}')
#אני מזמנת פונציה מדף PYB ובודקת איפה יש לי פצצה כלומר באיזה תמונה יש
#אני מזמנת את המודל של זיהוי חומרי הנפץ שיעשה לי כאן זיהוי
import torch
from PIL import Image, ImageDraw, ImageFont
import os
from glob import glob

import PYB

# טעינת המודל המאומן
model = torch.hub.load('ultralytics/yolov5', 'custom',
                       path='C:/Users/WIN 11/Desktop/yolov5-master/runs/train/model18/weights/best.pt')

# הגדרת המודל למצב דירוג
model.eval()

# הגדרת נתיב התיקייה המכילה את התמונות
folder_path = PYB.divide_image('mmmm.jpg')
output_folder = 'C:/Users/WIN 11/Desktop/Tunnel Project/Bombs/12356'  # הגדרת התיקייה לשמירת התמונות המעובדות

# יצירת התיקייה המצופה אם היא אינה קיימת
os.makedirs(output_folder, exist_ok=True)

# קבלת רשימת נתיבי קבצי התמונות בתיקייה
image_paths = glob(os.path.join(folder_path, '*.jpg')) + glob(os.path.join(folder_path, '*.png'))

# פתיחת קובץ טקסט לשמירת תוצאות הזיהוי
output_file = open('object_identification_results.txt', 'w')

# פונקציה לזיהוי אובייקטים בתמונה, הערכת האובייקטים המזוהים עם מלבני הגבול, תוויות קלאס וציוני אבטח, ושמירת התמונה
def detect_objects_and_annotate(image_path, output_folder):
    img = Image.open(image_path)
    results = model(img)  # ביצוע זיהוי אובייקטים
    draw = ImageDraw.Draw(img)
    font = ImageFont.load_default()  # ניתן גם לטעון גופן מסוים לקריאות טובה יותר
    # סימון האובייקטים המוכרים במלבני גבול, תוויות קלאס וציוני אמין
    for result in results.xyxy[0]:
        box = [result[0], result[1], result[2], result[3]]
        class_label = result[5]
        confidence = result[4]

        draw.rectangle(box, outline='red', width=2)
        draw.text((box[0], box[1]), f'{class_label} {confidence:.2f}', fill='red', font=font)

        # כתיבת תוצאות הזיהוי לקובץ טקסט
        output_file.write(f"Object: {class_label}, Confidence: {confidence:.2f}, Image: {os.path.basename(image_path)}\n")

    # שמירת התמונה עם הערכות בתיקיית הפלט
    img.save(os.path.join(output_folder, os.path.basename(image_path)))
    #print(f"Objects detected in: {os.path.basename(image_path)}")

# לולאה על כל תמונה בתיקייה, ביצוע זיהוי אובייקטים, הערכת התמונות, שמירת התמונות המעובדות וכתיבת תוצאות הזיהוי לקובץ טקסט
for image_path in image_paths:
    detect_objects_and_annotate(image_path, output_folder)

# סגירת קובץ הטקסט לאחר כתיבת תוצאות הזיהוי
output_file.close()

print("Images with recognized objects annotated and identification results saved in object_identification_results.txt")

# פונקציה לקריאת תמונות המזוהות מהקובץ ושמירתן במערך
def extract_identified_images(text_file_path):
    identified_images = []
    with open(text_file_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            if 'Image:' in line:
                image_name = line.split('Image: ')[1].strip().split('.')[0]
                identified_images.append(image_name)
        return identified_images

# נתיב לקובץ הטקסט שבו נשמרו תוצאות הזיהוי
text_file_path = 'object_identification_results.txt'

# קריאת שמות התמונות המזוהות מהקובץ ושמירתן במערך
identified_images_array = extract_identified_images(text_file_path)

# הדפסת מערך שמות התמונות בהן זוהו אובייקטים
print("Images with identified objects:", identified_images_array)


# פונקציה לכתיבת שמות התמונות המזוהות לקובץ טקסט
def write_identified_images_to_file(identified_images_array, output_file_path):
    with open(output_file_path, 'w') as file:
        for image_name in identified_images_array:
            file.write(f"{image_name}\n")

# נתיב לקובץ הטקסט שבו ישמרו שמות התמונות המזוהות
identified_images_file_path = 'identified_image_names.txt'

# כתיבת שמות התמונות המזוהות לקובץ הטקסט
write_identified_images_to_file(identified_images_array, identified_images_file_path)

print("Identified image names saved in the file identified_image_names.txt")


for p in identified_images_array:
    print(" ".join(str(os) for os in p))


# Iterate through each image in the folder, perform object detection, annotate the images,
if __name__ == '__main__':
    print('PyCharm')