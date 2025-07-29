from ultralytics import YOLO
import yaml
import torch


class yolov8TrainerClass:
    def __init__(self, baseModel, imageSize):
        self.epochs = 1
        self.imgSize = imageSize
        self.model = YOLO(baseModel)

    def trainYOLOv8(self, config, epochs, *args):
        # Convert args (tuple) to kwargs (dict)

        args = args[0][1:]
        kwargs = dict(zip(args[::2], args[1::2]))


        print(torch.cuda.is_available())
        for key, value in kwargs.items():
            if isinstance(value, float) and value.is_integer():
                print("is instance", key)
                kwargs[key] = int(value)
        results = self.model.train(
            data=config, epochs=epochs, imgsz=self.imgSize, pretrained=True, **kwargs
        )
        return results

    def resumeYOLOv8(self):
        results = self.model.train(
            resume=True
        )
        return results

    def exportModel(self, onnxPath):
        model = YOLO(onnxPath)
        model.export(format="onnx", nms= False, opset=14)

    def getClassNames(self, fileName):
        with open(fileName) as stream:
            try:
                dictValue = yaml.safe_load(stream)
            except yaml.YAMLError as exc:
                print(exc)
        return dictValue


def setYoloSettings(setting, inp_value):
    from ultralytics import settings

    for key, value in settings.items():
        print(key, value)
    print(value)
    settings.update({setting: inp_value})
