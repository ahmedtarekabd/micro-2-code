import cv2
import numpy as np

# Load the image
image = cv2.imread("./data/books1.jpg")

# Convert to grayscale (optional but recommended for edge detection)
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply edge detection (Canny edge detection is a common choice)
edges = cv2.Canny(gray, 50, 150, apertureSize=3)

# Define the parameter search range for circles (adjust based on your ball size)
min_radius = 10  # Minimum expected radius of the ball (in pixels)
max_radius = 30  # Maximum expected radius of the ball (in pixels)

# Apply Circular Hough Transform
circles = cv2.HoughCircles(edges, cv2.HOUGH_GRADIENT, 1, 20,
                          param1=50, param2=30)

print(circles)
cv2.imshow("Detected Balls", edges)
cv2.waitKey(0)

# Check if circles are found
if circles is not None:
  # Convert the circles from a 3D array to a list of dictionaries
  circles = np.uint16(np.around(circles))[0, :]
  
  # Draw detected circles on the original image
  for circle in circles:
    center_x, center_y, radius = circle[0], circle[1], circle[2]
    # Draw circle outline
    cv2.circle(image, (center_x, center_y), radius, (0, 255, 0), 2)
    # Draw circle center
    cv2.circle(image, (center_x, center_y), 2, (0, 0, 255), 3) 

  # Display the image with detected circles
  cv2.imshow("Detected Balls", image)
  cv2.waitKey(0)
else:
  print("No balls detected in the image")

# Close all windows
cv2.destroyAllWindows()
