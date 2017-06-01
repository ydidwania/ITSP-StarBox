
// Working of A .. working

int latchPin=13;
int count=0;
int level=0;
int clockPin=12;
int dataPin=11;
int mosfet[8]={10,9,8,7,6,5,4,3};
bool present[8][8]={{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}};

//bool a[8][8]={{1,0,1,1,1,1,1,1},{1,1,0,1,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,1,0,1,1,1},{1,1,1,1,1,0,1,1},{1,1,1,1,1,1,0,1},{1,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,1}};


//bool a[8][8]={{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1}};
//bool a[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
bool a[8][8] = {{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,0,0,0,0,0,1},{1,0,1,1,1,1,0,1},{1,1,0,1,1,0,1,1},{1,1,1,0,0,1,1,1},{1,1,1,1,1,1,1,1},{1,0,1,1,1,1,0,1}};

void controlmosfet(int current){
  //digitalWrite(latchPin,LOW);
  for(int foo=0;foo<8;foo++){
    digitalWrite(mosfet[foo],LOW);
  }
  digitalWrite(mosfet[current],HIGH);
}


void displayleds(int m,int level){
  for(int temp=0;temp<8;temp++){
    present[level][temp]=a[m][temp];
  }
  //digitalWrite(latchPin,LOW);
  updateShiftRegister();
  //digitalWrite(latchPin,HIGH);
  
  for(int temp=0;temp<8;temp++){
    present[level][temp]=1;
  }
  
  
}

void updateShiftRegister(){
  for(int i=0;i<8;i++){
    for (int j=0;j<8;j++){
      digitalWrite(clockPin,LOW);
      digitalWrite(dataPin,present[i][j]);
      digitalWrite(clockPin,HIGH);
    }
  }
}

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  for(int i=0;i<8;i++){
    pinMode(mosfet[i],OUTPUT);
  }
  // put your setup code here, to run once:

}


void loop() {
  count=count+1;
  level=(int(count/10))%8;
  //level=0;
  for(int m=0;m<8;m++){
    digitalWrite(latchPin,LOW);
    controlmosfet(m);
    displayleds(m,level);
    
    delay(1);
    digitalWrite(latchPin,HIGH);
  }
  
  
  
  // put your main code here, to run repeatedly:

}
