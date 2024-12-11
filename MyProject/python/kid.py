# import cv2
# import numpy as np
# from PIL import Image
# import face_recognition
# import os
#
# # Function to calculate face confidence based on face distance and match threshold
# def face_confidence(face_distance, face_match_threshold=0.6):
#     range = (1.0 - face_match_threshold)
#     linear_val = (1.0 - face_distance) / (range * 2.0)
#
#     if face_distance > face_match_threshold:
#         return str(round(linear_val * 100, 2)) + '%'
#     else:
#         value = (linear_val + ((1.0 - linear_val) * pow((linear_val - 0.5) * 2, 0.2))) * 100
#         return str(round(value, 2)) + '%'
#
# # Class for Face Recognition
# class FaceRecognition:
#     face_locations = []
#     face_encodings = []
#     face_names = []
#     known_face_encodings = []
#     known_face_names = []
#     process_current_frame = True
#     file_pointer = 0
#     identified_people = []
#
#     def __init__(self):
#         self.encode_faces()
#
#     def encode_faces(self):
#         for image in os.listdir('faces'):
#             face_image = face_recognition.load_image_file(f'faces/{image}')
#             face_encoding = face_recognition.face_encodings(face_image)[0]
#
#             self.known_face_encodings.append(face_encoding)
#             self.known_face_names.append(image.split('.')[0])
#
#     def run_recognition(self, image_path):
#         if not image_path:
#             self.face_names.append("NULL")
#             return
#
#         print("Processing image:", image_path)
#
#         pil_image = Image.open(image_path)
#
#         rgb_image = cv2.cvtColor(np.array(pil_image), cv2.COLOR_BGR2RGB)
#         face_locations = face_recognition.face_locations(rgb_image)
#         face_encodings = face_recognition.face_encodings(rgb_image, face_locations)
#
#         self.face_names = []
#
#         for face_encoding in face_encodings:
#             matches = face_recognition.compare_faces(self.known_face_encodings, face_encoding)
#             name = ' '
#             confidence = ' '
#
#             face_distances = face_recognition.face_distance(self.known_face_encodings, face_encoding)
#             best_match_index = np.argmin(face_distances)
#
#             if matches[best_match_index]:
#                 name = self.known_face_names[best_match_index]
#                 confidence = face_confidence(face_distances[best_match_index])
#                 self.identified_people.append(name)  # Add identified person to the list
#
#             self.face_names.append(f'{name} ({confidence})')
#
# # Create an instance of FaceRecognition
# face_recog_instance = FaceRecognition()
#
# def process_next_image():
#     global face_recog_instance
#
#     with open('image_paths.txt', 'r', encoding='utf-8') as file:
#         lines = file.readlines()
#
#         if face_recog_instance.file_pointer < len(lines):
#             image_path = lines[face_recog_instance.file_pointer].strip()
#             face_recog_instance.run_recognition(image_path)
#             face_recog_instance.file_pointer += 1
#         else:
#             print("No more images to process.")
#         print("Identified people:", face_recog_instance.identified_people)  # Print identified people
#
# # Call the function to process the next image
# process_next_image()
# # for p in face_recog_instance.identified_people:
# #     print(" ".join(str(os) for os in p))
#
# # Modify the existing code in Python to print the identified people's names in a format that can be parsed by C++
#
# # Modify the code where you print the identified people
# # print("Identified people:", face_recog_instance.identified_people)
#
# # Add the following code to format the names in a way that can be parsed easily by C++
# formatted_names = ', '.join(face_recog_instance.identified_people)
# print(formatted_names)







import cv2
import numpy as np
from PIL import Image
import face_recognition
import os
import sys

# Function to calculate face confidence based on face distance and match threshold
def face_confidence(face_distance, face_match_threshold=0.6):
    range = (1.0 - face_match_threshold)
    linear_val = (1.0 - face_distance) / (range * 2.0)

    if face_distance > face_match_threshold:
        return str(round(linear_val * 100, 2)) + '%'
    else:
        value = (linear_val + ((1.0 - linear_val) * pow((linear_val - 0.5) * 2, 0.2))) * 100
        return str(round(value, 2)) + '%'

# Class for Face Recognition
class FaceRecognition:
    face_locations = []
    face_encodings = []
    face_names = []
    known_face_encodings = []
    known_face_names = []
    process_current_frame = True
    identified_people = []

    def __init__(self):
        self.encode_faces()

    def encode_faces(self):
        for image in os.listdir('faces'):
            face_image = face_recognition.load_image_file(f'faces/{image}')
            face_encoding = face_recognition.face_encodings(face_image)[0]

            self.known_face_encodings.append(face_encoding)
            self.known_face_names.append(image.split('.')[0])

    def run_recognition(self, image_path):
        if not image_path:
            self.face_names.append("NULL")
            return

        print("Processing image:", image_path)

        pil_image = Image.open(image_path)

        rgb_image = cv2.cvtColor(np.array(pil_image), cv2.COLOR_BGR2RGB)
        face_locations = face_recognition.face_locations(rgb_image)
        face_encodings = face_recognition.face_encodings(rgb_image, face_locations)

        self.face_names = []

        for face_encoding in face_encodings:
            matches = face_recognition.compare_faces(self.known_face_encodings, face_encoding)
            name = ' '
            confidence = ' '

            face_distances = face_recognition.face_distance(self.known_face_encodings, face_encoding)
            best_match_index = np.argmin(face_distances)

            if matches[best_match_index]:
                name = self.known_face_names[best_match_index]
                confidence = face_confidence(face_distances[best_match_index])
                self.identified_people.append(name)  # Add identified person to the list

            self.face_names.append(f'{name} ({confidence})')

# Create an instance of FaceRecognition
face_recog_instance = FaceRecognition()

# Check if the image path is provided as a command-line argument
image_path = sys.argv[1]
face_recog_instance.run_recognition(image_path)
# else:
#     print("Please provide the path to the image as a command-line argument.")

# Print the identified people
print("Identified people:", face_recog_instance.identified_people)

# Format the names for C++ parsing
formatted_names = ', '.join(face_recog_instance.identified_people)
print(formatted_names)


if __name__ == '__main__':
    print('PyCharm')