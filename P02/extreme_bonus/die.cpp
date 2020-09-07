#include "die.h"

Die::Die(int faces){
    srand(time(NULL));
    if (faces<=0){ std::cerr<< "Error number of faces";}
    _faces=faces;
}
int Die::faces(){
    return _faces;    
}
int Die::value(){
    this->roll();
    return _value;
}
void Die::roll(){
    _value = rand()%_faces+1;
}