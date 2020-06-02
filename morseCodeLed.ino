char *morse[] = {".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. "};
char *letters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
char message[] = "cool";
char *commands[sizeof(message)];
const int ledPin = 13;

int count = 0;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  int indexNums[sizeof(message)];
  
  for(int i = 0; i < sizeof(message)-1; i++) {
    char temp = message[i];
    for(int j = 0; j < 26; j++){
      if ( temp == *letters[j] ) {
        indexNums[i] = j;
      }
    }
  }

  
  for(int i = 0; i < sizeof(message)-1; i++){
    commands[i] = morse[indexNums[i]];
//    Serial.println(commands[i]);
  }

  
  for(int i = 0; i < sizeof(message) - 1; i++){
    count += strlen(commands[i]);
  }

  count += sizeof(message)-1;
//  Serial.println(commands[2][1]);
  
  
}
  
void loop() {
  delay(3000);
  int intComm[count];
  int count2 = 0;
  for(int i = 0; i < sizeof(message)-1; i++){
    for(int j = 0; j < strlen(commands[i]); j++){
      if (commands[i][j] == '.'){
        intComm[count2] = 1;
      }else if(commands[i][j] == '-'){
        intComm[count2] = 2;
      }else if (commands[i][j] == ' '){
        intComm[count2] = 3; 
      }else{Serial.println("error");}
      count2++;
    }
  }
    
  for(int i = 0; i < count; i++) {
    if(intComm[i] == 1) {
      digitalWrite(ledPin, HIGH);
      delay(1000);  
      digitalWrite(ledPin, LOW);
      delay(1000);
    } else if(intComm[i] == 2) {
      digitalWrite(ledPin, HIGH);
      delay(3000);
      digitalWrite(ledPin, LOW);
      delay(1000);
    } else if(intComm[i] == 3) {
      if(i == count-1){
        break;
      }
      digitalWrite(ledPin, LOW);
      delay(3000);  
    }
  }

  digitalWrite(ledPin, LOW);
  delay(10000);

  
//  for(int i = 0; i < count; i++){
//      Serial.println(intComm[i]);
//  }
}
  
//  for(int z = 0; z < sizeof(message)-1; z++) {
//    Serial.println(commands[z]);
//    delay(500);  
//  }
