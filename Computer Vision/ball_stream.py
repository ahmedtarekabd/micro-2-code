import cv2
import numpy as np

# Define the parameter search range for circles (adjust based on your ball size)
min_radius = 10  # Minimum expected radius of the ball (in pixels)
max_radius = 30  # Maximum expected radius of the ball (in pixels)

# Open the video capture stream (change 0 to use an external camera)
cap = cv2.VideoCapture(0)

while True:
  # Capture frame-by-frame
  ret, frame = cap.read()

  # Convert to grayscale (optional but recommended for edge detection)
  gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
  blur = cv2.GaussianBlur(gray, (11, 11), 0)

  # # Apply edge detection (Canny edge detection is a common choice)
  # edges = cv2.Canny(blur, 50, 150, apertureSize=3)

  # Apply Circular Hough Transform
  circles = cv2.HoughCircles(blur, cv2.HOUGH_GRADIENT, 1.2, 20,
                            param1= 100, param2=30)
  
  # cv2.imshow("Detected Balls", edges)
  # cv2.waitKey(0)
  
  # Check if circles are found
  if circles is not None:
    # Convert the circles from a 3D array to a list of dictionaries
    circles = np.uint16(np.around(circles))[0, :]
    
    # Draw detected circles on the original image
    for circle in circles:
      center_x, center_y, radius = circle[0], circle[1], circle[2]
      # Draw circle outline
      cv2.circle(frame, (center_x, center_y), radius, (0, 255, 0), 2)
      # Draw circle center
      cv2.circle(frame, (center_x, center_y), 2, (0, 0, 255), 3) 

  # Display the resulting frame
  cv2.imshow('Ball Detection (Press q to quit)', frame)

  # Exit on 'q' press
  if cv2.waitKey(1) & 0xFF == ord('q'):
    break

# Release capture and clean up
cap.release()
cv2.destroyAllWindows()
