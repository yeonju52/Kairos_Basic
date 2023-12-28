// int s_idx = 3;
// int e_idx = 8;
// int len = e_idx - s_idx + 1;

// void setup() {
//   // put your setup code here, to run once:
//   for (int i = s_idx; i <= e_idx; i++){
//     pinMode(i, OUTPUT);
//   }
//   // char hello_c[] = "hello world";
//   // String hello = "hello world";
//   // hello.charAt(3)
// }

// int led_num = 0;
// void loop() {
//   // put your main code here, to run repeatedly:
//   for (int i = s_idx; i <= e_idx; i++){
//     if (((led_num) % len) + s_idx == i){
//       digitalWrite(i, HIGH);
//     }
//     else{
//       digitalWrite(i, LOW);
//     }
//     delay(10);
//   }
//   led_num++;
// }

int maxi = 7;
// int led[] = {3, 4, 5, 6, 7, 8};
int led[] = {4, 3, 6, 5, 8, 7};

void setup(){
  for (int i = 0; i < maxi; i++){
    pinMode(led[i], OUTPUT);
  }
}

int led_num = 0;
void loop(){
  for (int i = 0; i < maxi; i++){
    if (led_num == i){
      digitalWrite(led[i], HIGH);
    }
    else{
      digitalWrite(led[i], LOW);
    }
    delay(10);
  }
  led_num = (led_num+1) % maxi;
}