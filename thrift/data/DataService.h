/**
 * Autogenerated by Thrift Compiler (0.14.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef DataService_H
#define DataService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "data_server_types.h"

namespace astraea { namespace thrift { namespace data {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class DataServiceIf {
 public:
  virtual ~DataServiceIf() {}
  virtual void language_index(std::vector< ::astraea::thrift::data::Language> & _return) = 0;
  virtual void language_show( ::astraea::thrift::data::Language& _return, const std::string& id) = 0;
  virtual void language_create(const  ::astraea::thrift::data::Language& language) = 0;
  virtual void language_update(const  ::astraea::thrift::data::Language& language) = 0;
  virtual void language_delete(const std::string& id) = 0;
  virtual void get_language_script( ::astraea::thrift::data::Language& _return, const std::string& id) = 0;
};

class DataServiceIfFactory {
 public:
  typedef DataServiceIf Handler;

  virtual ~DataServiceIfFactory() {}

  virtual DataServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(DataServiceIf* /* handler */) = 0;
};

class DataServiceIfSingletonFactory : virtual public DataServiceIfFactory {
 public:
  DataServiceIfSingletonFactory(const ::std::shared_ptr<DataServiceIf>& iface) : iface_(iface) {}
  virtual ~DataServiceIfSingletonFactory() {}

  virtual DataServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(DataServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<DataServiceIf> iface_;
};

class DataServiceNull : virtual public DataServiceIf {
 public:
  virtual ~DataServiceNull() {}
  void language_index(std::vector< ::astraea::thrift::data::Language> & /* _return */) {
    return;
  }
  void language_show( ::astraea::thrift::data::Language& /* _return */, const std::string& /* id */) {
    return;
  }
  void language_create(const  ::astraea::thrift::data::Language& /* language */) {
    return;
  }
  void language_update(const  ::astraea::thrift::data::Language& /* language */) {
    return;
  }
  void language_delete(const std::string& /* id */) {
    return;
  }
  void get_language_script( ::astraea::thrift::data::Language& /* _return */, const std::string& /* id */) {
    return;
  }
};


class DataService_language_index_args {
 public:

  DataService_language_index_args(const DataService_language_index_args&);
  DataService_language_index_args& operator=(const DataService_language_index_args&);
  DataService_language_index_args() {
  }

  virtual ~DataService_language_index_args() noexcept;

  bool operator == (const DataService_language_index_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DataService_language_index_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_index_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DataService_language_index_pargs {
 public:


  virtual ~DataService_language_index_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_index_result__isset {
  _DataService_language_index_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DataService_language_index_result__isset;

class DataService_language_index_result {
 public:

  DataService_language_index_result(const DataService_language_index_result&);
  DataService_language_index_result& operator=(const DataService_language_index_result&);
  DataService_language_index_result() {
  }

  virtual ~DataService_language_index_result() noexcept;
  std::vector< ::astraea::thrift::data::Language>  success;
   ::astraea::thrift::Error e;

  _DataService_language_index_result__isset __isset;

  void __set_success(const std::vector< ::astraea::thrift::data::Language> & val);

  void __set_e(const  ::astraea::thrift::Error& val);

  bool operator == (const DataService_language_index_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DataService_language_index_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_index_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_index_presult__isset {
  _DataService_language_index_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DataService_language_index_presult__isset;

class DataService_language_index_presult {
 public:


  virtual ~DataService_language_index_presult() noexcept;
  std::vector< ::astraea::thrift::data::Language> * success;
   ::astraea::thrift::Error e;

  _DataService_language_index_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DataService_language_show_args__isset {
  _DataService_language_show_args__isset() : id(false) {}
  bool id :1;
} _DataService_language_show_args__isset;

class DataService_language_show_args {
 public:

  DataService_language_show_args(const DataService_language_show_args&);
  DataService_language_show_args& operator=(const DataService_language_show_args&);
  DataService_language_show_args() : id() {
  }

  virtual ~DataService_language_show_args() noexcept;
  std::string id;

  _DataService_language_show_args__isset __isset;

  void __set_id(const std::string& val);

  bool operator == (const DataService_language_show_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const DataService_language_show_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_show_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DataService_language_show_pargs {
 public:


  virtual ~DataService_language_show_pargs() noexcept;
  const std::string* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_show_result__isset {
  _DataService_language_show_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DataService_language_show_result__isset;

class DataService_language_show_result {
 public:

  DataService_language_show_result(const DataService_language_show_result&);
  DataService_language_show_result& operator=(const DataService_language_show_result&);
  DataService_language_show_result() {
  }

  virtual ~DataService_language_show_result() noexcept;
   ::astraea::thrift::data::Language success;
   ::astraea::thrift::Error e;

  _DataService_language_show_result__isset __isset;

  void __set_success(const  ::astraea::thrift::data::Language& val);

  void __set_e(const  ::astraea::thrift::Error& val);

  bool operator == (const DataService_language_show_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DataService_language_show_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_show_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_show_presult__isset {
  _DataService_language_show_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DataService_language_show_presult__isset;

class DataService_language_show_presult {
 public:


  virtual ~DataService_language_show_presult() noexcept;
   ::astraea::thrift::data::Language* success;
   ::astraea::thrift::Error e;

  _DataService_language_show_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DataService_language_create_args__isset {
  _DataService_language_create_args__isset() : language(false) {}
  bool language :1;
} _DataService_language_create_args__isset;

class DataService_language_create_args {
 public:

  DataService_language_create_args(const DataService_language_create_args&);
  DataService_language_create_args& operator=(const DataService_language_create_args&);
  DataService_language_create_args() {
  }

  virtual ~DataService_language_create_args() noexcept;
   ::astraea::thrift::data::Language language;

  _DataService_language_create_args__isset __isset;

  void __set_language(const  ::astraea::thrift::data::Language& val);

  bool operator == (const DataService_language_create_args & rhs) const
  {
    if (!(language == rhs.language))
      return false;
    return true;
  }
  bool operator != (const DataService_language_create_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_create_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DataService_language_create_pargs {
 public:


  virtual ~DataService_language_create_pargs() noexcept;
  const  ::astraea::thrift::data::Language* language;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_create_result__isset {
  _DataService_language_create_result__isset() : e(false) {}
  bool e :1;
} _DataService_language_create_result__isset;

class DataService_language_create_result {
 public:

  DataService_language_create_result(const DataService_language_create_result&);
  DataService_language_create_result& operator=(const DataService_language_create_result&);
  DataService_language_create_result() {
  }

  virtual ~DataService_language_create_result() noexcept;
   ::astraea::thrift::Error e;

  _DataService_language_create_result__isset __isset;

  void __set_e(const  ::astraea::thrift::Error& val);

  bool operator == (const DataService_language_create_result & rhs) const
  {
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DataService_language_create_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_create_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_create_presult__isset {
  _DataService_language_create_presult__isset() : e(false) {}
  bool e :1;
} _DataService_language_create_presult__isset;

class DataService_language_create_presult {
 public:


  virtual ~DataService_language_create_presult() noexcept;
   ::astraea::thrift::Error e;

  _DataService_language_create_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DataService_language_update_args__isset {
  _DataService_language_update_args__isset() : language(false) {}
  bool language :1;
} _DataService_language_update_args__isset;

class DataService_language_update_args {
 public:

  DataService_language_update_args(const DataService_language_update_args&);
  DataService_language_update_args& operator=(const DataService_language_update_args&);
  DataService_language_update_args() {
  }

  virtual ~DataService_language_update_args() noexcept;
   ::astraea::thrift::data::Language language;

  _DataService_language_update_args__isset __isset;

  void __set_language(const  ::astraea::thrift::data::Language& val);

  bool operator == (const DataService_language_update_args & rhs) const
  {
    if (!(language == rhs.language))
      return false;
    return true;
  }
  bool operator != (const DataService_language_update_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_update_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DataService_language_update_pargs {
 public:


  virtual ~DataService_language_update_pargs() noexcept;
  const  ::astraea::thrift::data::Language* language;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_update_result__isset {
  _DataService_language_update_result__isset() : e(false) {}
  bool e :1;
} _DataService_language_update_result__isset;

class DataService_language_update_result {
 public:

  DataService_language_update_result(const DataService_language_update_result&);
  DataService_language_update_result& operator=(const DataService_language_update_result&);
  DataService_language_update_result() {
  }

  virtual ~DataService_language_update_result() noexcept;
   ::astraea::thrift::Error e;

  _DataService_language_update_result__isset __isset;

  void __set_e(const  ::astraea::thrift::Error& val);

  bool operator == (const DataService_language_update_result & rhs) const
  {
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DataService_language_update_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_update_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_update_presult__isset {
  _DataService_language_update_presult__isset() : e(false) {}
  bool e :1;
} _DataService_language_update_presult__isset;

class DataService_language_update_presult {
 public:


  virtual ~DataService_language_update_presult() noexcept;
   ::astraea::thrift::Error e;

  _DataService_language_update_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DataService_language_delete_args__isset {
  _DataService_language_delete_args__isset() : id(false) {}
  bool id :1;
} _DataService_language_delete_args__isset;

class DataService_language_delete_args {
 public:

  DataService_language_delete_args(const DataService_language_delete_args&);
  DataService_language_delete_args& operator=(const DataService_language_delete_args&);
  DataService_language_delete_args() : id() {
  }

  virtual ~DataService_language_delete_args() noexcept;
  std::string id;

  _DataService_language_delete_args__isset __isset;

  void __set_id(const std::string& val);

  bool operator == (const DataService_language_delete_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const DataService_language_delete_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_delete_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DataService_language_delete_pargs {
 public:


  virtual ~DataService_language_delete_pargs() noexcept;
  const std::string* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_delete_result__isset {
  _DataService_language_delete_result__isset() : e(false) {}
  bool e :1;
} _DataService_language_delete_result__isset;

class DataService_language_delete_result {
 public:

  DataService_language_delete_result(const DataService_language_delete_result&);
  DataService_language_delete_result& operator=(const DataService_language_delete_result&);
  DataService_language_delete_result() {
  }

  virtual ~DataService_language_delete_result() noexcept;
   ::astraea::thrift::Error e;

  _DataService_language_delete_result__isset __isset;

  void __set_e(const  ::astraea::thrift::Error& val);

  bool operator == (const DataService_language_delete_result & rhs) const
  {
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DataService_language_delete_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_language_delete_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_language_delete_presult__isset {
  _DataService_language_delete_presult__isset() : e(false) {}
  bool e :1;
} _DataService_language_delete_presult__isset;

class DataService_language_delete_presult {
 public:


  virtual ~DataService_language_delete_presult() noexcept;
   ::astraea::thrift::Error e;

  _DataService_language_delete_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DataService_get_language_script_args__isset {
  _DataService_get_language_script_args__isset() : id(false) {}
  bool id :1;
} _DataService_get_language_script_args__isset;

class DataService_get_language_script_args {
 public:

  DataService_get_language_script_args(const DataService_get_language_script_args&);
  DataService_get_language_script_args& operator=(const DataService_get_language_script_args&);
  DataService_get_language_script_args() : id() {
  }

  virtual ~DataService_get_language_script_args() noexcept;
  std::string id;

  _DataService_get_language_script_args__isset __isset;

  void __set_id(const std::string& val);

  bool operator == (const DataService_get_language_script_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const DataService_get_language_script_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_get_language_script_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DataService_get_language_script_pargs {
 public:


  virtual ~DataService_get_language_script_pargs() noexcept;
  const std::string* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_get_language_script_result__isset {
  _DataService_get_language_script_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DataService_get_language_script_result__isset;

class DataService_get_language_script_result {
 public:

  DataService_get_language_script_result(const DataService_get_language_script_result&);
  DataService_get_language_script_result& operator=(const DataService_get_language_script_result&);
  DataService_get_language_script_result() {
  }

  virtual ~DataService_get_language_script_result() noexcept;
   ::astraea::thrift::data::Language success;
   ::astraea::thrift::Error e;

  _DataService_get_language_script_result__isset __isset;

  void __set_success(const  ::astraea::thrift::data::Language& val);

  void __set_e(const  ::astraea::thrift::Error& val);

  bool operator == (const DataService_get_language_script_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DataService_get_language_script_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataService_get_language_script_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DataService_get_language_script_presult__isset {
  _DataService_get_language_script_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DataService_get_language_script_presult__isset;

class DataService_get_language_script_presult {
 public:


  virtual ~DataService_get_language_script_presult() noexcept;
   ::astraea::thrift::data::Language* success;
   ::astraea::thrift::Error e;

  _DataService_get_language_script_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class DataServiceClient : virtual public DataServiceIf {
 public:
  DataServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  DataServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void language_index(std::vector< ::astraea::thrift::data::Language> & _return);
  void send_language_index();
  void recv_language_index(std::vector< ::astraea::thrift::data::Language> & _return);
  void language_show( ::astraea::thrift::data::Language& _return, const std::string& id);
  void send_language_show(const std::string& id);
  void recv_language_show( ::astraea::thrift::data::Language& _return);
  void language_create(const  ::astraea::thrift::data::Language& language);
  void send_language_create(const  ::astraea::thrift::data::Language& language);
  void recv_language_create();
  void language_update(const  ::astraea::thrift::data::Language& language);
  void send_language_update(const  ::astraea::thrift::data::Language& language);
  void recv_language_update();
  void language_delete(const std::string& id);
  void send_language_delete(const std::string& id);
  void recv_language_delete();
  void get_language_script( ::astraea::thrift::data::Language& _return, const std::string& id);
  void send_get_language_script(const std::string& id);
  void recv_get_language_script( ::astraea::thrift::data::Language& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class DataServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<DataServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (DataServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_language_index(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_language_show(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_language_create(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_language_update(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_language_delete(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get_language_script(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  DataServiceProcessor(::std::shared_ptr<DataServiceIf> iface) :
    iface_(iface) {
    processMap_["language_index"] = &DataServiceProcessor::process_language_index;
    processMap_["language_show"] = &DataServiceProcessor::process_language_show;
    processMap_["language_create"] = &DataServiceProcessor::process_language_create;
    processMap_["language_update"] = &DataServiceProcessor::process_language_update;
    processMap_["language_delete"] = &DataServiceProcessor::process_language_delete;
    processMap_["get_language_script"] = &DataServiceProcessor::process_get_language_script;
  }

  virtual ~DataServiceProcessor() {}
};

class DataServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  DataServiceProcessorFactory(const ::std::shared_ptr< DataServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< DataServiceIfFactory > handlerFactory_;
};

class DataServiceMultiface : virtual public DataServiceIf {
 public:
  DataServiceMultiface(std::vector<std::shared_ptr<DataServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~DataServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<DataServiceIf> > ifaces_;
  DataServiceMultiface() {}
  void add(::std::shared_ptr<DataServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void language_index(std::vector< ::astraea::thrift::data::Language> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->language_index(_return);
    }
    ifaces_[i]->language_index(_return);
    return;
  }

  void language_show( ::astraea::thrift::data::Language& _return, const std::string& id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->language_show(_return, id);
    }
    ifaces_[i]->language_show(_return, id);
    return;
  }

  void language_create(const  ::astraea::thrift::data::Language& language) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->language_create(language);
    }
    ifaces_[i]->language_create(language);
  }

  void language_update(const  ::astraea::thrift::data::Language& language) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->language_update(language);
    }
    ifaces_[i]->language_update(language);
  }

  void language_delete(const std::string& id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->language_delete(id);
    }
    ifaces_[i]->language_delete(id);
  }

  void get_language_script( ::astraea::thrift::data::Language& _return, const std::string& id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get_language_script(_return, id);
    }
    ifaces_[i]->get_language_script(_return, id);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class DataServiceConcurrentClient : virtual public DataServiceIf {
 public:
  DataServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  DataServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void language_index(std::vector< ::astraea::thrift::data::Language> & _return);
  int32_t send_language_index();
  void recv_language_index(std::vector< ::astraea::thrift::data::Language> & _return, const int32_t seqid);
  void language_show( ::astraea::thrift::data::Language& _return, const std::string& id);
  int32_t send_language_show(const std::string& id);
  void recv_language_show( ::astraea::thrift::data::Language& _return, const int32_t seqid);
  void language_create(const  ::astraea::thrift::data::Language& language);
  int32_t send_language_create(const  ::astraea::thrift::data::Language& language);
  void recv_language_create(const int32_t seqid);
  void language_update(const  ::astraea::thrift::data::Language& language);
  int32_t send_language_update(const  ::astraea::thrift::data::Language& language);
  void recv_language_update(const int32_t seqid);
  void language_delete(const std::string& id);
  int32_t send_language_delete(const std::string& id);
  void recv_language_delete(const int32_t seqid);
  void get_language_script( ::astraea::thrift::data::Language& _return, const std::string& id);
  int32_t send_get_language_script(const std::string& id);
  void recv_get_language_script( ::astraea::thrift::data::Language& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}}} // namespace

#endif
