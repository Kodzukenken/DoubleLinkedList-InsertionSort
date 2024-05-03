#include <iostream>
#include <limits>
using namespace std;

// insertion sort

void printArray(int data[], int number) {
  for (int i = 0; i <number; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
  cout<<endl;
}

void descending(int data[], int number){
  for (int i = 1; i < number; i++) {
    int key = data[i];
    int j = i - 1; 
    while (key > data[j] && j >= 0) { //places j ahead of key when greater
      data[j + 1] = data[j]; 
      --j;
    }
    data[j + 1] = key; //places key in array
    printArray(data, number);
  }
}	

void ascending(int data[], int number){
  for (int i = 1; i < number; i++) {
    int key = data[i]; 
    int j = i - 1;
    while (key < data[j] && j >= 0) {
      data[j + 1] = data[j];
      --j;
    }
    data[j + 1] = key;
    printArray(data, number);
  }
}	

void sequential(int data[], int number, int search){
	 int j = 0;
	 int i;
	//  moves one by one as usual
      for(i = 0; i < number; i++)
      {
            if(data[i]==search)
            {
                  j = 1;
                  break;
            }
      }	
      if(j==1){
            cout<<"Value founded in index "<<i<<endl;
            cout<<endl;
	  }
      else{
      		cout<<"Value not found!"<<endl;
	  }      
}

void binaryAsc(int data[], int left, int right, int search){
	int j = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "Mid: " << mid << endl;
        if (data[mid] == search){
        	cout << "Value founded in index " << mid;
        	cout << endl;
        	cout << endl;
			j = 1;
			break;	
		}
        if (search > data[mid]){
             left = mid + 1;  
			//  prints halved array
			for(int i = mid; i <= right; i++ ){
				cout << data[i] << " ";
			}   
			 cout<<"Left: "<< left <<endl;
		}
        else{
            right = mid - 1;
			for(int i = mid; i >= left; i-- ){
			cout << data[i] << " ";
			}         
			cout<<"Right: "<< right <<endl;	
		}	
    }
      if(j==0){
      		cout<<"Value not found!"<<endl;
	  }
}

void binaryDesc(int data[], int left, int right, int search){
	int j = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
		cout << "Mid: " << mid << endl;
        if (data[mid] == search){
        	cout << "Value founded in index " << mid;
        	cout << endl;
        	cout << endl;
			j = 1;
			break;	
		}
        if (search < data[mid]){
            left = mid + 1; 
			for(int i = mid; i <= right; i++ ){
				cout << data[i] << " ";
			}   
			cout << endl <<"Left: "<< left <<endl;	
		}
        else{
        	right = mid - 1;
			for(int i = mid; i >= left; i-- ){
			cout << data[i] << " ";
			}   
			 cout << endl <<"Right: "<< left <<endl;
		}
    }
      if(j == 0){
      		cout<<"Value not found!"<<endl;
	  }
}


int main(){
	int number, sortMenu, search, searchMenu;
	cout<<"Enter number of data: ";
// make sure input is number
	while(!(cin >> number)){
		cin.clear();
	// ignores input until enter is pressed, ask for valid
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Input valid number of data: ";
	}
// create array and enter values
	int data[number];
	for(int i = 0; i<number; i++){
		cout << "Value " << (i+1) << " : ";
		cin >> data[i];
	}
	cout << endl;
	printArray(data, number);

// menu settings
do{
	cout << "1. Ascending" << endl;
	cout << "2. Descending" << endl;
	cout << "3. Exit(go to searching)" << endl;
	cout << "Choose: ";
	while(!(cin >> sortMenu)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Input valid menu: ";
	}
	switch(sortMenu){
		case(1):
			ascending(data,number);
			printArray(data,number);
			break;

		case(2):
			descending(data,number);
			printArray(data,number);
			break;
			
		case(3):
			break;
		
		default:
			cout<<"Not in the menu!"<<endl;
	}
}while(sortMenu!=3);
	cout<<endl;
// 2nd menu
do{
	cout<<"Menu"<<endl;
	cout<<"1. Sequential Search"<<endl;
	cout<<"2. Binary Search"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"Choose: ";
		while(!(cin >> searchMenu)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Input valid menu: ";
			}
	switch(searchMenu){
		case(1):
			cout << "Input searched value: ";
			cin >> search;
			printArray(data, number);
			sequential(data, number, search);
			break;
		
		case(2):
			cout << "Input searched value: ";
			cin >> search;

			// loop inside
				do{
					cout<<"Menu"<<endl;
					cout<<"1. Ascending"<<endl;
					cout<<"2. Descending"<<endl;
					cout<<"3. Exit"<<endl;
					cout<<"Choose: ";
					cout<<endl;
						while(!(cin >> sortMenu)){
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Input valid menu: ";
						}
					switch(sortMenu){
						case(1):
							ascending(data, number);
							printArray(data, number);
							binaryAsc(data, 0, (number-1), search);					
							break;
				
						case(2):
							descending(data, number);
							printArray(data, number);
							binaryDesc(data, 0, (number-1), search);
							break;
						case(3):
							break;
						
						default:
							cout << "Not in the menu!" <<endl;
					}
				}while(sortMenu!=3);
	}

}while(searchMenu!=3);
	return 0;
	}

