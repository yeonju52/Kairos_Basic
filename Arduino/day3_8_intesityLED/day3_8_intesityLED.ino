int maxi = 7;
int led[] = {3, 5, 6, 9, 10, 11};

void setup(){
  for (int i = 0; i < maxi; i++){
    pinMode(led[i], OUTPUT);
  }
}

int intensity = 0;
int minus = 1;
void loop(){
  if (intensity == 256){
    minus = -1;
    intensity = 255;
  }
  if (intensity == -1){
    minus = 1;
    intensity = 0;
  }
  for (int i = 0; i < maxi; i++){
    analogWrite(led[i], intensity++);
  }
  delay(500);
  intensity += minus;
}

// for (int i = 0; i < 255; i++){
//     analogWrite(3, i);
//     delay(10);
//   }
// }
// int maxi = 7;
// int led[] = {3, 5, 6, 9, 10, 11};

// void setup(){
//   for (int i = 0; i < maxi; i++){
//     pinMode(led[i], OUTPUT);
//   }
// }

// int led_num = 0;
// int intensity = 0;
// void loop(){
//   for (int i = 0; i < maxi; i++){
//     if (led_num == i){
//       analogWrite(led[i], intensity);
//     }
//     else{
//       analogWrite(led[i], LOW);
//     }
//     delay(10);
//   }
//   led_num = (led_num+1) % maxi;
//   intensity = (intensity + 1) % 256;

// }

// // for (int i = 0; i < 255; i++){
// //     analogWrite(3, i);
// //     delay(10);
// //   }
// // }