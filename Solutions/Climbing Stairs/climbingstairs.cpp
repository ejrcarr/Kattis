#include <iostream>

int main() {
    int num_steps_required, registration_desk, office;
    scanf("%d %d %d", &num_steps_required, &registration_desk, &office);

    // Need to visit office and then desk
    int to_office_and_desk = office + abs(office - registration_desk);
    bool ALREADY_FINISHED_STEPS = to_office_and_desk >= num_steps_required;
    
    // If walking to office and then desk already meets requirements
    if(ALREADY_FINISHED_STEPS) {
        std::cout << to_office_and_desk + registration_desk;
        return 0;
    }


    int steps_leftover = abs(num_steps_required - to_office_and_desk);
    bool ARE_STEPS_LEFTOVER_EVEN = steps_leftover % 2 == 0;

    // if there are even leftover steps we could just go back and forth
    // if there are odd leftover steps we could add one to make it even 
    // to then go back and forth

    // Start a step from the desk (20 + 1) = 21
    
    // 50 20 10 -> 50 - (10 + (20 - 10)) = 30
    // 21 20  ...  21 20
    //  1  2  ...  49 50
    
    // 51 20 10  ->  51 - (10 + (20 - 10)) = 31
    // If it is odd:
    // 21 20  ...  20 21 (+ 1) 20
    //  1  2  ...  50 51       52
    int total_steps = ARE_STEPS_LEFTOVER_EVEN ? num_steps_required : (num_steps_required + 1);
    
    total_steps += registration_desk;

    printf("%d", total_steps);
    return 0;
}
