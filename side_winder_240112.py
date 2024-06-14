import numpy as np
import cv2,serial, time

portNum = 'COM7'

ser = serial.Serial(portNum, 115200)

cap = cv2.VideoCapture(0)

cap.set(3, 320)
cap.set(4, 320)

lower_hue = np.array([-5, 100, 100])
upper_hue = np.array([5, 255, 255])

def moment_check(fme,contList):
    lth = len(contList)
    # cx, cy = [],[]
    for i in range(lth):
        cnt = contList[i]
        M = cv2.moments(cnt)
        # cx.append(int(M['m10']/M['m00']))
        # cy.append(int(M['m01']/M['m00']))
        # cv2.putText(fme, f'x: {cx[i]},y: {cy[i]}',(cx[i]-50,cy[i]-50),cv2.FONT_HERSHEY_COMPLEX,0.5,(255,255,255),1,cv2.LINE_AA)
        # cv2.drawMarker(fme,(cx[i],cy[i]), color = (0,150,0),markerType=cv2.MARKER_TILTED_CROSS,thickness = 3)
        cx = int(M['m10']/M['m00'])
        cy = int(M['m01']/M['m00'])
        
        cv2.putText(fme, f'x: {cx},y: {cy}',(cx-50,cy-50),cv2.FONT_HERSHEY_COMPLEX,0.5,(255,255,255),1,cv2.LINE_AA)
        cv2.drawMarker(fme,(cx,cy), color = (0,150,0),markerType=cv2.MARKER_TILTED_CROSS,thickness = 3)
        center_data ='a' + str(cx) + 'b' +str(cy) + 'c' + str(frame.shape[0]) + 'd' + str(frame.shape[1]) +'e'
        print(center_data)
        ser.write(center_data.encode('utf-8'))
        # print(ser.read().decode())
        #time.sleep(1)
    return


while True:
    ret, frame = cap.read()
    frame = cv2.flip(frame, 1)
    if ret:
        # Convert the frame to HSV
        img_hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        
        # Create a mask for the red regions
        img_mask = cv2.inRange(img_hsv, lower_hue, upper_hue)

        # 모멘트를 구하는 코드
        try: 
            cont_list, hierachy = cv2.findContours(img_mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
            cv2.drawContours(frame, cont_list,-1,(0,255,0), 3)

            # print('here')
            lth = len(cont_list)

            # if 1<=lth <= 2:
            if lth == 1:
                # print('here2')
                moment_check(frame,cont_list)

                # print('here3')
               
        except ZeroDivisionError:
            print('Error!')

        # cv2.imshow('raw img',img_mask)
        cv2.imshow('my choonsik',frame)
    if cv2.waitKey(1) == 27:
       cv2.destroyAllWindows()
       break