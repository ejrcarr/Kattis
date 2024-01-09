#include <iostream>

int main() {
    int m, l, M, L, tM, tL, starting_pos = 0;
    std::cin >> m >> l >> M >> L >> tM >> tL;

    // complete m first then l
    int m_first = abs(m - starting_pos) + abs(M - m);
    int l_second = m_first + abs(l - M) + abs(L - l);

    // complete l first then m
    int l_first = abs(l - starting_pos) + abs(L - l);
    int m_second = l_first + abs(m - L) + abs(M - m);
   
    // leave m off at l and ocntinue to move L
    int start_m_to_l_to_L = abs(m - starting_pos) + abs(m - l) + abs(L - l);
    int L_to_l_to_M = start_m_to_l_to_L + abs(l - L) + abs(M - l);

    // leave l off at m then continue to move m
    int start_l_to_m_to_M = abs(l - starting_pos) + abs(l - m) + abs(M - m);
    int M_to_m_to_L = start_l_to_m_to_M + abs(m - M) + abs(L - m);

    if(!((m_first <= tM && l_second <= tL) || 
        (l_first <= tL && m_second <= tM) ||
        (L_to_l_to_M <= tM && start_m_to_l_to_L <= tL) ||
        (M_to_m_to_L <= tL && start_l_to_m_to_M <= tM))) {
        std::cout << "im";
    }
    std::cout << "possible";
    return 0;
}