#include <iostream>
#include <cassert>
#include <string>

int decoder(const std::string &message){
	if (message.size() == 1) return 1;
	if (message.size() == 2) return (std::stoi(message) > 26 ? 1 : 2);
	if (std::stoi(message.substr(0,2)) > 26) return decoder(message.substr(1));
	return decoder(message.substr(1)) + decoder(message.substr(2));
}


int main() {
    assert(decoder("111") == 3);
    return 0;
}