#include <iostream>
using namespace std;
int main(){
    int numque,numchoice;
    string question,response,typeofquestions;

    

    cout << "Welcome to the Quiz Fun project!!\nPlease chose your question type from the list below.\nA.choose the best answer\nB.Fill in the blanks\ninput: ";
    cin >> typeofquestions;
    if(typeofquestions == "A"){
        cout << "Number of questions: ";
        cin >> numque;
        cout << "Number of choices each question have(Maximum = 5): ";
        cin >> numchoice;
        cin.ignore();
        while(numchoice > 5){                                                            // starts the program
            cout << "Number of choices each question have(Maximum = 5): ";
            cin >> numchoice;
            cin.ignore();
        }
        
        string *Questions = new string[numque];
        string choices[numque][numchoice];
        string *Answer = new string[numque];
        string *guess = new string[numque];

         //-----------------------------------------------------------
        for(int i = 0; i<numque ; ++i){
            cout << "Question no " << i+1 <<": ";
            getline(cin,Questions[i]);
            for(int j = 0; j< numchoice; j++){
                cout << "choice " << char(j+65) <<": ";  // taking input from the examiner
                getline(cin,choices[i][j]);
            }
            cout <<"Answer: ";
            cin >> Answer[i]; 
            cin.ignore(); 
            while(Answer[i].length() >1 ){
                cout << "Please use the character next to the choice\nAnswer: ";
                cin>>Answer[i];
                cin.ignore();
                cout << endl;
            }
        }
        //--------------------------------------------------------
        for(int i=0;i<15;i++){
            cout << endl;
        }
        cout << "Do you wanna start the quiz(y/n): ";
        cin >> response;

        while(response == "y"){
                int correctguesses = 0;
                cout << "-----------------------QuizTime ------------------";
                cout <<endl;
                for(int i = 0; i<numque;i++){
                    cout << i+1 <<". " << Questions[i] << "?";
                    cout << endl;                                               //asks the questions to the examinee
                    for(int j = 0; j<numchoice;j++){
                        cout << char(j+65) <<". " << choices[i][j];
                        cout <<endl;

                    }
                    cout <<"Your Answer: ";
                    cin >> guess[i];
                    if(Answer[i]==guess[i]){
                        cout <<"You are correct!!!"<<endl;
                        correctguesses += 1;
                    }else{
                        cout <<"You are wrong :)"<<endl;
                        cout <<"The correct answer was " << Answer[i] << endl;    
                    }
                }
            //---------------------------------------------------------------
            cout <<"-------------Results!!--------------"<<endl;
            cout << correctguesses << " out of " << numque << endl;            //desplays the result
            cout << "Do you wanna start the quiz(y/n): ";
            cin >> response;
            //----------------------------------------------------------------
        }
    }
    //-----------------------------------------------------------
    else if(typeofquestions == "B"){
        cout << "Number of questions: ";
        cin >> numque;
        string* fillquestions = new string[numque];
        string* fillanswer = new string[numque];
        string* useranswer = new string[numque];
        for(int i = 0; i<numque ; ++i){
            cout << "Question no " << i+1 <<": ";
            getline(cin,fillquestions[i]);               //takes fill in the blanks input from the examiner
            cin.ignore();
            cout << endl;
            cout <<"Answer: ";
            getline(cin,fillanswer[i]); 
            cin.ignore();
            cout << endl;
        }
        //----------------------------------------------------
        
    }
    
    

   
    
}