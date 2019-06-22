#include "libxml/parser.h"
#include "libxml/xmlmemory.h"
#include <iostream>
#include <string>
#include <cstdlib>

void parseMethod(xmlDocPtr doc, xmlNodePtr cur, std::string *methodOption)
{
  cur=cur->xmlChildrenNode;
  while(cur!=NULL)
  {
    if(!(xmlStrcmp(cur->name,(const xmlChar*)"option")))
    {
      methodOption->append((const char*)xmlGetProp(cur,(const xmlChar*)"name"));
      methodOption->append("=");
      if(xmlNodeListGetString(doc,cur->xmlChildrenNode,1)!=NULL)
      {
        methodOption->append((const char*)xmlNodeListGetString(doc,cur->xmlChildrenNode,1));
      }
      methodOption->append(":");
    }
    cur=cur->next;
  }
  methodOption->erase(methodOption->end()-1);
}

void parseData(xmlDocPtr doc, xmlNodePtr cur, std::string *dataOption)
{
  cur=cur->xmlChildrenNode;
  while(cur!=NULL)
  {
    if(!(xmlStrcmp(cur->name,(const xmlChar*)"option")))
    {
      dataOption->append((const char*)xmlGetProp(cur,(const xmlChar*)"name"));
      dataOption->append("=");
      if(xmlNodeListGetString(doc,cur->xmlChildrenNode,1)!=NULL)
      {
        dataOption->append((const char*)xmlNodeListGetString(doc,cur->xmlChildrenNode,1));
      }
      dataOption->append(":");
    }
    cur=cur->next;
  }
  dataOption->erase(dataOption->end()-1);
}

void parseFactoryOption(xmlDocPtr doc, xmlNodePtr cur, std::string *factoryOption)
{
  cur=cur->xmlChildrenNode;
  while(cur!=NULL)
  {
    if(!(xmlStrcmp(cur->name,(const xmlChar*)"option")))
    {
      factoryOption->append((const char*)xmlGetProp(cur,(const xmlChar*)"name"));
      factoryOption->append("=");
      if(xmlNodeListGetString(doc,cur->xmlChildrenNode,1)!=NULL)
      {
        factoryOption->append((const char*)xmlNodeListGetString(doc,cur->xmlChildrenNode,1));
      }
      factoryOption->append(":");
    }
    cur=cur->next;
  }
  factoryOption->erase(factoryOption->end()-1);
}

int main()
{
  xmlDocPtr doc;
  xmlNodePtr cur;
  std::string factoryOption;
  std::string dataOption;
  std::string methodOption;

  // Open configuration file
  doc=xmlParseFile("config.xml");
  // Check if the file is parsed
  if(doc==NULL)
  {
    std::cout<<"Document not found.\n";
    exit(1);
  }

  // Point to the root of the xml
  cur=xmlDocGetRootElement(doc);
  if(cur==NULL)
  {
    std::cout<<"The document is empty.\n";
    exit(1);
  }
  // Check the root node
  else if(xmlStrcmp(cur->name,(const xmlChar*)"configuration"))
  {
    std::cout<<"This is not a configuration file in the right format.\n";
    xmlFreeDoc(doc);
    exit(1);
  }
  else if(xmlStrcmp(xmlGetProp(cur,(const xmlChar*)"type"),(const xmlChar*)"BDT"))
  {
    std::cout<<"This is not a config file for BDT.\n";
    exit(1);
  }
  else
  {
    std::cout<<"Configuration file loaded. Parsing...\n";
  }

  // Go to the children of root
  cur=cur->xmlChildrenNode;
  while(cur!=NULL)
  {
    if(!(xmlStrcmp(cur->name,(const xmlChar*)"factory")))
    {
      parseFactoryOption(doc,cur,&factoryOption);
    }
    if(!(xmlStrcmp(cur->name,(const xmlChar*)"data")))
    {
      parseData(doc,cur,&dataOption);
    }
    if(!(xmlStrcmp(cur->name,(const xmlChar*)"method")))
    {
      parseMethod(doc,cur,&methodOption);
    }
    cur=cur->next;
  }

  std::cout<<"The factory option is \n\t"<<factoryOption<<std::endl;
  std::cout<<"The data option is \n\t"<<dataOption<<std::endl;
  std::cout<<"The method option is \n\t"<<methodOption<<std::endl;
  xmlFreeDoc(doc);
  return 0;

}
