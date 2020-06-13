An XML-based configuration mechanism using C++ for a Boosted Decision Tree (BDT) of TMVA framework, which is widely used in high energy physics research.

TMVA framework provides lots of multivariate analysis tools with highly customizable configuration options of each method. By creating a separate configuration file, the users can avoid hard coding the options in the source file and therefore save time from re-compiling, which also reduces the risk of creating extra bugs by not touching the source code of a working program. The configuration file is chosen to be the type of XML because of the following reasons: 
    1. XML file works well across platforms
    2. XML file can be easily used by multiple popular languages. There are also plenty of third-party libraries for XML.
    3. XML file is relatively readable compared to most of coding languages so it makes it possible to examine the configuration file by just eye-balling the file.
    4. XML has mature validation rules which ensure the configurations are setup correctly before being fed in the program.
The XML file of this project is written for the BDT of TMVA specifically. All available options of the BDT are included in the XML file.

Since TMVA is a framework of C++, this project uses the language of C++ and related library The C++ program mainly works as a parser for extracting the configuration options from the XML file. The options can then be further delivered to the BDT setup. In an actual physics analysis, this project can be converted into a library and leveraged when it's needed.