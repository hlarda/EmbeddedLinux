 #include <iostream>
/*function with default argument or parameter*/
void print(std::string str="Hello World") {
    std::cout << str << std::endl;
}

int main(){
    /*prints default value*/
    print();
    /*but u can pass another*/
    print("other text than default");
}