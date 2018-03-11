#include <iostream>

bool isMachine_x64bit(); //prttp

int main()
{
    std::cout << "Is machine 64 bit: " << (isMachine_x64bit() ? "YES" : "NO") << std::endl;
    return 0;
}

bool isMachine_x64bit(){
        int ExtendedFeatureFlags;
        asm ("mov $0x80000001, %%eax; "
             "cpuid; "
             "mov %%edx, %0; "
             :"=r"(ExtendedFeatureFlags)
             :
             :"%eax","%ebx","%ecx","%edx"
        );
        return ExtendedFeatureFlags & (1 << 29);
}
