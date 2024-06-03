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
        left = i * part_width
        upper = 0
        right = (i + 1) * part_width
        lower = height
        part = image.crop((left, upper, right, lower))

        part.save(os.path.join(output_folder, f'{i}.png'))

    print("Image divided and parts saved successfully!")

    return output_folder


# Specify the image path
image_path = 'a.jpg'

# Call the function to divide the image and get the output folder path
output_folder_path = divide_image(image_path)

print("Output folder path: ", output_folder_path)

#
# def divide_image_into_five_queues(image_path):
#     # Open the image
#     img = Image.open(image_path)
#
#     # Get the dimensions of the image
#     width, height = img.size
#
#     # Calculate the width of each part
#     part_width = width // 5
#
#     # Divide the image into five equal parts horizontally
#     for i in range(5):
#         left = i * part_width
#         upper = 0
#         right = (i + 1) * part_width
#         lower = height
#         part = img.crop((left, upper, right, lower))
#
#         # Save each part as a separate image
#         part.save(f"{i + 1}.png")
#
#     print("Image divided into five equal parts horizontally.")
#
# image_path = "a.jpg"
#
# # Call the function with the image path
# divide_image_into_five_queues(image_path)

if __name__ == '__main__':
    print('PyCharm')
