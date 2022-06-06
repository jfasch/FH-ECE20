#ifndef TESTS_FIXTURES_H
#define TESTS_FIXTURES_H

#include <gtest/gtest.h>

#include <string>
#include <stdlib.h>


class TestWithTemporaryFile : public ::testing::Test
{
public:
    TestWithTemporaryFile()
    : _fd(-1) 
    {
        _tmpfilename = ::testing::UnitTest::GetInstance()->current_test_info()->name();
        _tmpfilename += "XXXXXX";

        auto filenametemplate = std::make_unique<char[]>(_tmpfilename.size()+1);
        
        strcpy(filenametemplate.get(), _tmpfilename.c_str());

        _fd = ::mkstemp(filenametemplate.get());
        if (_fd == -1)
            throw std::runtime_error(std::string("mkstemp: ") + _tmpfilename);

        _tmpfilename = filenametemplate.get();
    }
    ~TestWithTemporaryFile()
    {
        if (_fd != -1)
            ::close(_fd);
    }

    const std::string& tmpfilename() const { return _tmpfilename; }
    int tmpfd() const { return _fd; }

private:
    std::string _tmpfilename;
    int _fd;
};

#endif
