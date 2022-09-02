/* Scope resolution operator
  #include <iostream>
  using namespace std;
  class box {
     private:
          int length;
     public:
           box (){
               length = 0;
           }
           int printLength (box); //friend function
  };
  int box :: printLength (box b) {
      b. length +=10;
      return b. length;
  }
  int main () {
     box b;
     cout <<"Length : " <<printLength (b)<<endl;
      return 0;
  }
*/

/* Friend Function
  #include <iostream>
  using namespace std;
  class box {
     private:
          int length;
     public:
           box (){
               length = 0;
           }
     friend int printLength (box); //friend function
  };
  int printLength (box b) {
      b. length +=10;
      return b. length;
  }
  int main () {
     box b;
     cout <<"Length : " <<printLength (b)<<endl;
      return 0;
  }
*/