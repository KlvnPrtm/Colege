from imageai.Detection import ObjectDetection
from PIL import Image
import easygui
import os

def get_input_path():
    while True:
        input_path = easygui.fileopenbox(title="Pilih File Gambar", filetypes=["*.png", "*.jpg", "*.jpeg"])
        if input_path:
            return input_path
        else:
            os.system("cls")
            print("Pilih File")

def get_output_path(output_directory, output_filename,output_name):
    count = 1
    base_output_path = os.path.join(output_directory, output_filename)
    
    while os.path.exists(base_output_path):
        output_filename = f"{output_name}_copy{count}.jpg"
        base_output_path = os.path.join(output_directory, output_filename)
        count += 1

    return base_output_path

def perform_object_detection(input_path, output_path, model_path):
    detector = ObjectDetection()
    detector.setModelTypeAsRetinaNet()
    detector.setModelPath(model_path)
    detector.loadModel()

    detections = detector.detectObjectsFromImage(
        input_image=input_path,
        output_image_path=output_path,
        minimum_percentage_probability=30
    )

    new_image = Image.open(output_path)

    for detected_object in detections:
        print(detected_object["name"], " : ", detected_object["percentage_probability"], " : ", detected_object["box_points"])
        print("--------------------------------")

    new_image.show()

def main():
    input_path = get_input_path()
    model_path = "./model/resnet50_coco_best_v2.1.0.h5"

    output_directory = easygui.diropenbox(title="Select Output Directory")
    output_filename = easygui.enterbox("Enter desired output filename (without extension):")
    
    output_name = output_filename
    
    if not output_filename:
        output_filename = "new"

    output_filename = f"{output_filename}.jpg"
    output_path = get_output_path(output_directory, output_filename,output_name)

    print(f"Output Filename: {os.path.basename(output_path)}")
    print(f"Output Path: {output_path}")

    perform_object_detection(input_path, output_path, model_path)

    another_image = easygui.buttonbox("Do you want to process another image?", choices=["Yes", "No"])
    if another_image == "No":
        exit()

if __name__ == "__main__":
    main()
