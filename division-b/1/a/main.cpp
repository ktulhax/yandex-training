#include <iostream>

int GetFinalVerdict(int nExitCode, int nInteractorVerdict, int nCheckerVerdict)
{
    switch (nInteractorVerdict)
    {
        case 0:
            return nExitCode != 0 ? 3 : nCheckerVerdict;
        case 1:
            return nCheckerVerdict;
        case 4:
            return nExitCode != 0 ? 3 : 4;
        case 6:
            return 0;
        case 7:
            return 1;
        default:
            return nInteractorVerdict;
    }
}

int main()
{
    int nExitCode, nInteractorVerdict, nCheckerVerdict;
    std::cin >> nExitCode;
    std::cin >> nInteractorVerdict;
    std::cin >> nCheckerVerdict;
    std::cout << GetFinalVerdict(nExitCode, nInteractorVerdict, nCheckerVerdict) << std::endl;
    return 0;
}
