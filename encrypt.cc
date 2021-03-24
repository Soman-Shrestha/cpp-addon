#include <node.h>
#include "encrypt.h"
namespace demo {
  using v8::Exception;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void Encrypt(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Number> num;
    if(args.Length() == 3){
        double value = args[0].As<Number>()->Value() + args[1].As<Number>()->Value() + args[2].As<Number>()->Value();
        num = Number::New(isolate, value);
    }
    else {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
      return;
    }

    args.GetReturnValue().Set(num);
  }
    void InitEncrypt(Local<Object> exports) {
        NODE_SET_METHOD(exports, "encrypt", Encrypt);
    }
}