from ultralytics import YOLO
from ultralytics.models.yolo.detect.predict import DetectionPredictor

model = YOLO('yolov8s.pt') # yolov3-v7

results = model.predict(source=0, show=True, save_txt=True, save_conf=True, save_crop=True, augment=True, project='runs/detect', name='exp', exist_ok=True)
# while True:
#     results = model.predict(source=0, stream=True)
#     print("ahmed")
#     i = 0
#     for result in results:
#         print(result.boxes)
#         print(result.summary())
#         result.show()
#         i += 1
#     print(i)
#     break

