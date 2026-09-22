#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale >= 1);

    uint64_t result = 0;
    for (uint32_t bit = 0; bit < 64; ++bit) {
        const uint64_t expanded = uint64_t{bit} * scale;
        if (expanded >= 64) {
            break;
        }
        if ((input & (uint64_t{1} << bit)) != 0) {
            result |= uint64_t{1} << expanded;
        }
    }
    return result;
}

int main() {
    assert(expand(0b1111, 3) == 0b001001001001);
    assert(expand(0b0101, 2) == 0b00010001);
    assert(expand(0, 1) == 0);
    assert(expand(UINT64_MAX, 1) == UINT64_MAX);
    assert(expand(UINT64_MAX, 64) == 1);
    assert(expand(UINT64_MAX, 65) == 1);
    return 0;
}
