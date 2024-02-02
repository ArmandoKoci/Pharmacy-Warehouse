#include <iostream>            
#include <string>


using namespace std;     
 class PharmacyStore{
 	private:
 		string products[50]; //�� ����� � ������� ��� �� 50 ������.(��������� ������������).
 		int nextIndex; //������� ��������� �������� ���� ��� �������� �������� (� ������� ���).
 	public:
 		PharmacyStore(){
 			nextIndex=0; //������� �� ��������� ��� �� ���� 0 ������ ��������� �������.
		 }
		 
    void insertProduct(string product){ //���� ����� ��� ����� ����������� ������� � ������������ ��� ������ ��� ������� ��� ����� ���������� ����� ���� ������ ��� �� �� �������.
    	if(nextIndex>=50){ 
    		cout << " unfortunately the store is full of products. "<< endl; //������� �����.
    		return;
		} 
		products[nextIndex]=product;
		cout<<product<<" has been added successfully to the store."<<endl;
		nextIndex++; //��������� ��� ������ ��� ������
		
	}
	
	void deleteProduct(string product){  //�������� ��������� �� ���� ��� ������ ��� ���� �������� ���� ���� ������ ��� �� ������ ��� 0-50.
		   int index = searchProduct(product);
		   if(index == -1){
		   	cout<<" Product not found."<<endl;
		   	return;
		   }  
		  
		 products[index]="DELETED";
		 cout<<product<<" the product has been successfully deleted."<<endl;    	
		}
		
	
	void updateProduct(string oldproduct, string newproduct){ //��������� �������� �� ���� ��� ������.������������� ���� �������� �� ����.
	    int index = searchProduct(oldproduct);
	    if(index == -1){
	    	cout<<" No product was found on the store." << endl; //���������� ��� ������� �� ������ ��� store ���.
	    	return;
		}
		products[index] = newproduct; //������� ������ ������ �������� ��������� �� ��� �����. 
		cout << oldproduct <<" the product name has been successfully updated to "<<newproduct<<"."<<endl;
	}
		
	int searchProduct(string product) { //��������� �������� �� ���� ��� ������ ��� ���� ���� ������.
		for(int i=0; i<nextIndex; i++){ 
			if(products[i] == product) { //���������� �� ������ ��� ���� ��� ��������� ���� ��������� ���� ������ ��� ���� ������ ��� return i.
				return i;
			}
		}
		return -1; //�� ��������� ��� ��� ������� ������ ������� -1.
	}
	
	void displayProducts() { //������� �������� ��� ���������� ���.
		cout << "Pharmacy Products: "<< endl;
		for(int i =0; i<nextIndex; i++) {
			cout << i <<". " << products[i] << endl;
		}
	}

};

int main() {
	
	PharmacyStore store;
	int choice,index;
	string product;
	string newproduct;
	
	do{ //MENU
		cout<<"Pharmacy Management System"<<endl;
		cout<<"1. Insert Product"<<endl;
		cout<<"2. Search Product"<<endl;
		cout<<"3. Delete Product"<<endl;
		cout<<"4. Update Product"<<endl;
		cout<<"5. Display Products"<<endl;
		cout<<"6. Exit"<<endl;	
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				 cout<<"Enter the product name to insert: ";
				 cin>>product;
				 store.insertProduct(product);
				break;
			
			case 2:
				cout<<"Enter the product to search: "; //��������� ��������� �� ���� ��� ������ 0-50.
				cin>>product;
				index=store.searchProduct(product);
				if(index == -1){ //��� ������ = -1 ��� ������� ������ ������ ����� � ����� ����� 0-50.
					cout<<" Product not found on the store!"<<endl;
				} else{
					cout<<product<<" Product found! "<<index<<endl;
				}
				break;
							 
			case 3:
				cout<<"Enter the name of the product to delete: ";
				cin>>product;
				store.deleteProduct(product);	
				break;
					 		 	 
			case 4:
				cout<<"Enter the product name to update: ";
				cin>>product;
				cout<<"Enter the new product name: ";
				cin>>newproduct;
				store.updateProduct(product,newproduct);
				break;
					 				
			case 5:
				store.displayProducts();
				break;
					 			 			
			case 6:
				cout<<"Exiting from the store..."<<endl;
				break;
					 			
			default:
		    	cout<<"Invalid choice, try again."<<endl;	
		}
		
		cout<<endl;
						
}while(choice != 6);
	
	return 0;
}
