CPPFLAGS=-Wall -DNDEBUG -g2

#location of the Python header files
PYTHON_VERSION = 3.5
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)

#location of the Boost Python include files and library
BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

.PHONY: all clean

#all: $(TARGET)

TARGET= PythonWrapper
	#g++ $(CPPFLAGS) $< -o $(TARGET) $(LIBS)

$(TARGET).so: $(TARGET).o
	g++ $(CPPFLAGS) -shared -Wl,--export-dynamic $(TARGET).o -L$(BOOST_LIB) -l:libboost_python-py$(subst .,,$(PYTHON_VERSION)).so -o $(TARGET).so -lntl -lgmp -lm -lfhe

$(TARGET).o: $(TARGET).cpp
	g++ -I$(PYTHON_INCLUDE) -I$(BOOST_INC) $(LIBS) -fPIC -c $(TARGET).cpp

all: $(TARGET).so

clean:
	rm -f $(TARGET).so
