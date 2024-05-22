#קבלת תמונה וחלוקה שלה לחלקים שווים
from PIL import Image
import os

#פונקציה שמחזירה את המיקום של התקיה שבו חילקו את התקיה
def divide_image(image_path):
    output_folder = 'output_parts/'

    # טען את התמונה
    image = Image.open(image_path)

    # קבל את הרוחב והגובה של התמונה
    width, height = image.size

    # חשב גבהים של קו
    line_height = height // 3
    third_line_start = 2 * line_height

    # צור תיקיית פלט אם היא לא קיימת
    os.makedirs(output_folder, exist_ok=True)
    #
    # # חלקו את התמונה לשלוש שורות
    # first_line = image.crop((0, 0, width, line_height))
    # second_line = image.crop((0, line_height, width, 2 * line_height))
    # third_line = image.crop((0, third_line_start, width, height))

    # חלקו את השורה השלישית לחמישה חלקים
    part_width = width // 5

    for i in range(5):
        part = image.crop((i * part_width, 0, (i + 1) * part_width, line_height))
        part.save(os.path.join(output_folder, f'{i}.jpg'))

    print("Image divided and parts saved successfully!")

    return output_folder


# Specify the image path
image_path = 'mmmm.jpg'

# Call the function to divide the image and get the output folder path
output_folder_path = divide_image(image_path)

print("Output folder path: ", output_folder_path)



if __name__ == '__main__':
    print('PyCharm')
