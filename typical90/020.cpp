#include <iostream>

long long A, B, C;
long long E = 1;

int main() {
	std::cin >> A >> B >> C;
	for (int i = 1; i <= B; i++) E *= C;
	if (A < E) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	
    return 0;
}
