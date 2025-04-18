#ifndef MOCK_FILE_DIALOG_H
#define MOCK_FILE_DIALOG_H
#include <QString>

class MockFileDialog
{
public:
    static QString getOpenFileName() { return "test.mp3"; }
};
#endif // MOCK_FILE_DIALOG_H
