// -----------------------------------------------------------------------------------
// XMLNodeImpl.H - TXMLNode Helper
//
// $Rev: 68920 $
//
// Copyright(c) 1995-2011 Embarcadero Technologies, Inc.
// -----------------------------------------------------------------------------------
#ifndef XMLNodeImp_h
#define XMLNodeImp_h

#include <Xml.XMLDoc.hpp>

// Macro to delegate all IXMLNode methods to TXMLNode for
// XML Data Binding classes.

#define __IXMLNODE_IMPL_BASE__ \
  virtual HRESULT __stdcall QueryInterface(REFIID IID, void **Obj)  { \
    return Xml::Xmldoc::TXMLNode::QueryInterface(IID, (void**)Obj); \
  } \
  virtual ULONG __stdcall AddRef() { \
    return Xml::Xmldoc::TXMLNode::_AddRef(); \
  } \
  virtual ULONG __stdcall Release()  { \
    return Xml::Xmldoc::TXMLNode::_Release(); \
  } \
  virtual System::OleVariant __fastcall GetAttribute(const System::UnicodeString AttrName){ \
    return Xml::Xmldoc::TXMLNode::GetAttribute(AttrName); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNodeList __fastcall GetAttributeNodes(){ \
    return Xml::Xmldoc::TXMLNode::GetAttributeNodes(); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNodeList __fastcall GetChildNodes(){ \
    return Xml::Xmldoc::TXMLNode::GetChildNodes(); \
  } \
  virtual System::OleVariant __fastcall GetChildValue(const System::OleVariant &IndexOrName){ \
    return Xml::Xmldoc::TXMLNode::GetChildValue(IndexOrName); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNodeCollection __fastcall GetCollection(){ \
    return Xml::Xmldoc::TXMLNode::GetCollection(); \
  } \
  virtual Xml::Xmldom::_di_IDOMNode __fastcall GetDOMNode(){ \
    return Xml::Xmldoc::TXMLNode::GetDOMNode(); \
  } \
  virtual bool __fastcall GetHasChildNodes(){ \
    return Xml::Xmldoc::TXMLNode::GetHasChildNodes(); \
  } \
  virtual bool __fastcall GetIsTextElement(){ \
    return Xml::Xmldoc::TXMLNode::GetIsTextElement(); \
  } \
  virtual System::UnicodeString __fastcall GetLocalName(){ \
    return Xml::Xmldoc::TXMLNode::GetLocalName(); \
  } \
  virtual System::UnicodeString __fastcall GetNamespaceURI(){ \
    return Xml::Xmldoc::TXMLNode::GetNamespaceURI(); \
  } \
  virtual System::UnicodeString __fastcall GetNodeName(){ \
    return Xml::Xmldoc::TXMLNode::GetNodeName(); \
  } \
  virtual Xml::Xmlintf::TNodeType __fastcall GetNodeType(){ \
    return Xml::Xmldoc::TXMLNode::GetNodeType(); \
  } \
  virtual System::OleVariant __fastcall GetNodeValue(){ \
    return Xml::Xmldoc::TXMLNode::GetNodeValue(); \
  } \
  virtual Xml::Xmlintf::_di_IXMLDocument __fastcall GetOwnerDocument(){ \
    return Xml::Xmldoc::TXMLNode::GetOwnerDocument(); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall GetParentNode(){ \
    return Xml::Xmldoc::TXMLNode::GetParentNode(); \
  } \
  virtual System::UnicodeString __fastcall GetPrefix(){ \
    return Xml::Xmldoc::TXMLNode::GetPrefix(); \
  } \
  virtual bool __fastcall GetReadOnly(){ \
    return Xml::Xmldoc::TXMLNode::GetReadOnly(); \
  } \
  virtual System::UnicodeString __fastcall GetText(){ \
    return Xml::Xmldoc::TXMLNode::GetText(); \
  } \
  virtual System::UnicodeString __fastcall GetXML(){ \
    return Xml::Xmldoc::TXMLNode::GetXML(); \
  } \
  virtual void __fastcall SetAttribute(const System::UnicodeString AttrName, const System::OleVariant &Value){ \
    Xml::Xmldoc::TXMLNode::SetAttribute(AttrName, Value); \
  } \
  virtual void __fastcall SetChildValue(const System::OleVariant &IndexOrName, const System::OleVariant &Value){ \
    Xml::Xmldoc::TXMLNode::SetChildValue(IndexOrName, Value); \
  } \
  virtual void __fastcall SetNodeValue(const System::OleVariant &Value){ \
    Xml::Xmldoc::TXMLNode::SetNodeValue(Value); \
  } \
  virtual void __fastcall SetReadOnly(const bool Value){ \
    Xml::Xmldoc::TXMLNode::SetReadOnly(Value); \
  } \
  virtual void __fastcall SetText(const System::UnicodeString Value){ \
    Xml::Xmldoc::TXMLNode::SetText(Value); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall AddChild(const System::UnicodeString TagName, int Index = 0xffffffff){ \
    return Xml::Xmldoc::TXMLNode::AddChild(TagName, Index); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall AddChild(const System::UnicodeString TagName, const System::UnicodeString NamespaceURI, bool GenPrefix = false, int Index = 0xffffffff){ \
    return Xml::Xmldoc::TXMLNode::AddChild(TagName, NamespaceURI, GenPrefix, Index); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall CloneNode(bool Deep){ \
    return Xml::Xmldoc::TXMLNode::CloneNode(Deep); \
  } \
  virtual void __fastcall DeclareNamespace(const System::UnicodeString Prefix, const System::UnicodeString URI){ \
    Xml::Xmldoc::TXMLNode::DeclareNamespace(Prefix, URI); \
  } \
  virtual System::UnicodeString __fastcall FindNamespaceURI(const System::UnicodeString TagOrPrefix){ \
    return Xml::Xmldoc::TXMLNode::FindNamespaceURI(TagOrPrefix); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall FindNamespaceDecl(const System::UnicodeString NamespaceURI){ \
    return Xml::Xmldoc::TXMLNode::FindNamespaceDecl(NamespaceURI); \
  } \
  virtual System::OleVariant __fastcall GetAttributeNS(const System::UnicodeString AttrName, const System::UnicodeString NamespaceURI){ \
    return Xml::Xmldoc::TXMLNode::GetAttributeNS(AttrName, NamespaceURI); \
  } \
  virtual bool __fastcall HasAttribute(const System::UnicodeString Name){ \
    return Xml::Xmldoc::TXMLNode::HasAttribute(Name); \
  } \
  virtual bool __fastcall HasAttribute(const System::UnicodeString Name, const System::UnicodeString NamespaceURI){ \
    return Xml::Xmldoc::TXMLNode::HasAttribute(Name, NamespaceURI); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall NextSibling(){ \
    return Xml::Xmldoc::TXMLNode::NextSibling(); \
  } \
  virtual void __fastcall Normalize(){ \
    return Xml::Xmldoc::TXMLNode::Normalize(); \
  } \
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall PreviousSibling(){ \
    return Xml::Xmldoc::TXMLNode::PreviousSibling(); \
  } \
  virtual void __fastcall Resync(){ \
    Xml::Xmldoc::TXMLNode::Resync(); \
  } \
  virtual void __fastcall SetAttributeNS(const System::UnicodeString AttrName, const System::UnicodeString NamespaceURI, const System::OleVariant &Value){ \
    Xml::Xmldoc::TXMLNode::SetAttributeNS(AttrName, NamespaceURI, Value); \
  } \
  virtual void __fastcall TransformNode(const Xml::Xmlintf::_di_IXMLNode stylesheet, const Xml::Xmlintf::_di_IXMLDocument output){ \
    Xml::Xmldoc::TXMLNode::TransformNode(stylesheet, output); \
  }


#ifdef _DELPHI_NEXTGEN
  #define __IXMLNODE_IMPL__  __IXMLNODE_IMPL_BASE__ \
    virtual void __fastcall TransformNode(const Xml::Xmlintf::_di_IXMLNode stylesheet, System::UnicodeString &output){ \
      Xml::Xmldoc::TXMLNode::TransformNode(stylesheet, output); \
    }
#else
  #define __IXMLNODE_IMPL__  __IXMLNODE_IMPL_BASE__ \
    virtual void __fastcall TransformNode(const Xml::Xmlintf::_di_IXMLNode stylesheet, System::WideString &output){ \
      Xml::Xmldoc::TXMLNode::TransformNode(stylesheet, output); \
    }
#endif


// Macro to delegate all IXMLNodeCollection methods to TXMLNodeCollection for
// XML Data Binding classes.

#define __IXMLNODECOLLECTION_IMPL__ \
    __IXMLNODE_IMPL__ \
  virtual int __fastcall GetCount(){ \
      return Xml::Xmldoc::TXMLNodeCollection::GetCount(); \
    } \
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall GetNode(int Index){ \
      return Xml::Xmldoc::TXMLNodeCollection::GetNode(Index); \
    } \
  virtual void __fastcall Clear(){ \
      Xml::Xmldoc::TXMLNodeCollection::Clear(); \
    } \
  virtual void __fastcall Delete(int Index){ \
      Xml::Xmldoc::TXMLNodeCollection::Delete(Index); \
    } \
  virtual int __fastcall Remove(const Xml::Xmlintf::_di_IXMLNode Node){ \
      return Xml::Xmldoc::TXMLNodeCollection::Remove(Node); \
    }

// Helper class template function to create collections
//
// Example Call:
//  CollectionCreater<_di_IXMLbookTypeList, TXMLbookTypeList, IXMLbookType>::DoCreate(this, Fbook, "book");


template <typename CollIntfType, typename CollClassType, typename CollItemType>
class CollectionCreater
{
public:
  static void DoCreate(Xml::Xmldoc::TXMLNode* Node, CollIntfType& result, System::UnicodeString name) {
    Xml::Xmldoc::_di_IXMLNodeAccess nodeAccess;
    Xml::Xmldoc::TXMLNodeCollection* c;
    Node->GetInterface(nodeAccess);
    c = nodeAccess->CreateCollection(__classid(CollClassType), __uuidof(CollItemType), name);
    c->GetInterface(result);
  }
};


#endif


