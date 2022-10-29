#pragma once
bool checkInput(string input){
	for(int i =0; i < input.length();i++){
		if(isdigit(input[i]) == false ){
			return false;
		}
	}return true;
	
	
}

