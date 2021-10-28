# DocumentScanner

This project is a simple OpenCV Qt application.  
Its goal is to warp documents from input images.

Application processing can be described as:
1. Read input image from passed path
2. Convert image to grayscale
3. Apply threshold
4. Apply blur
5. Detect edges
6. Dilate edges
7. Find contours
8. Find document corners in contours
9. Warp image

