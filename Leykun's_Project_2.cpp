#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    string userinput;
    int numstud,numsubj;
    cout << "Enter no of students: ";
    cin >> numstud;
    cout << "Enter no of subject: ";
    cin >> numsubj;
    string *studlist = new string[numstud];
    string subjgrade[numstud][numsubj];
    int subjmark[numstud][numsubj];
    string *subjlist = new string[numsubj];
    float *average = new float[numstud];
    int *credithr = new int[numsubj];
    int gradepoint[numstud][numsubj];
    float *CGPA = new float[numstud];
    float *CGPA1 = new float[numstud];
        //-------------------------------------
        for(int i = 0; i<numsubj; i++){    //recives input from the user about the subject names
            cout <<"Enter the name of subject " << i+1 <<"(4characters): ";
            cin >>subjlist[i];
            while((subjlist[i].length()) !=4){
                cout<<"bad boy, what did i say 4 char only\n";
                cout <<"Enter the name of subject " << i+1 <<": ";
                cin>>subjlist[i];
            }
            cout << "Credit hour: ";
            cin >> credithr[i];
        }
        //-------------------------------------
        for(int i = 0; i < numstud; i++){ //stores student ids and their grades 
            cout << "Student ID: ",cin>>studlist[i];
            while((studlist[i].length() != 11)){
                cout << "ID length must be 11 char long try again!\n";
                cout << "Student ID: ",cin>>studlist[i];
            }
            for(int j = 0; j<numsubj; j++){
                cout << subjlist[j] << "(out of 100): ";
                cin >> subjmark[i][j];
            }
        }
        //---------------------------------------
        for(int i = 0; i<numstud;i++){//calculates average of each student and stores it in an array of average
            float sum = 0.0;
            for(int j = 0; j<numsubj;j++){
                sum += subjmark[i][j];
            }
            average[i]=sum/numsubj;
        }
        //-----------------------------------------
        for(int i = 0; i<7;i++){ //prints out the table
            if(i==0){
                cout<<"\t\t\t\t student mark list\n";
            }else if(i==1){
                for(int j = 0; j<6;j++ ){
                    cout << "__________________";
                }
                cout << endl;
            } else if(i==2){
                cout<<"Student. ID\t\t";
                for(int i =0;i<numsubj;i++){
                    cout<<subjlist[i]<<"\t\t";
                }
                cout<<"average\t\t";
                cout<< "CGPA\t\t";
                cout<<endl;
            }
        //-----------------------------------------------
        }
        for(int i = 0; i < numstud; i++){  //data storage of the students Grade and Gradepoint
            for(int j = 0; j<numsubj; j++){
                if(subjmark[i][j]>= 85 && subjmark[i][j]<=100){
                    subjgrade[i][j] = "A ";
                    gradepoint[i][j] = 4;
                }else if(subjmark[i][j] <40){
                    subjgrade[i][j] = "F ";
                    gradepoint[i][j] = 0;
                }else if(subjmark[i][j]>=75 && subjmark[i][j] <85){
                    subjgrade[i][j] = "B+";
                    gradepoint[i][j] = 3.5;
                }else if(subjmark[i][j] >=70 && subjmark[i][j] <75){
                    subjgrade[i][j] = "B ";
                    gradepoint[i][j] = 3;
                }else if(subjmark[i][j]>=60 && subjmark[i][j]<70){
                    subjgrade[i][j] = "C+";
                    gradepoint[i][j] = 2.5;
                }else if(subjmark[i][j]>=50 && subjmark[i][j] < 60){
                    subjgrade[i][j] = "C ";
                    gradepoint[i][j] = 2;
                }else if(subjmark[i][j]>=40 && subjmark[i][j] < 50){
                    subjgrade[i][j] = "D ";
                    gradepoint[i][j] = 1.5;
                }else{
                    subjgrade[i][j] = "NA ";
                    gradepoint[i][j] = 0;
                }
            }
        }
        //-------------------------------------
        float crhrsummation = 0.0;        
        for(int i = 0; i < numsubj;i++){
            crhrsummation += credithr[i];
        }
        for(int i = 0; i<numstud;i++){    //this batch calculatess the cgpa of each student using their credit hour
            float sumation = 0.0;
            for(int j = 0; j<numsubj;j++){
                sumation += credithr[j]*gradepoint[i][j];
            }
            CGPA[i] = sumation/crhrsummation;
        }
        //--------------------------------------
        for(int i = 0; i<numstud;i++){
            cout << studlist[i]; 
            for(int j = 0; j<numsubj;j++){
                cout <<"\t\t" << subjmark[i][j] << " : " << subjgrade[i][j];     // printa the contents of the table
            }
            cout <<"\t\t"<<average[i];
            cout <<"\t\t"<<CGPA[i];
            cout << endl;
        }
        //--------------------------------------      ranking students still in progress
        /*cout << "Enter A to rank the top 5 students\n";
        cout << "Enter B to search for student by their ID\nINPUT: ";
        cin >> userinput;
        if(userinput == "A"){
            for(int i = 0; i<numstud;i++){
                CGPA1[i]= CGPA[i];
                for(int j = 0; j<numstud;j++){
                    if(CGPA1[i]<CGPA[j]){
                        CGPA1[i] = CGPA[j];
                    }
                }
            }
        }
        for(int i = 0; i<numstud;i++)
            cout << CGPA1[i] << " ";*/
}
