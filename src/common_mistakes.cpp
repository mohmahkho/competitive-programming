std::vector<int> vec {1}; // vector containing only value 1

for(int i = 0; i < vec.size() - 2; ++i) {
    std::cout << vec[i] << std::endl;
}

/*
this part of code seems to work because [vec.size() - 2 = -1] and 0 is not
less than -1 so it will not even enter the loop;
but since size() member function returns an unsigned value this is actually
an underflow.
*/

// the right way:
for(int i = 0; i < (int)vec.size() - 2; i++) {
    std::cout << vec[i] << std::endl;
}
