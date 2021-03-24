#include <node.h>
#include "decrypt.h"
namespace demo {

    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Decrypt(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    Local<Number> num;
    if(args.Length() == 2){
        double value = args[0].As<Number>()->Value() + args[1].As<Number>()->Value();
        num = Number::New(isolate, value);
    }
    else {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    args.GetReturnValue().Set(num);
    }
    void InitDecrypt(Local<Object> exports) {
        NODE_SET_METHOD(exports, "decrypt", Decrypt);
    }
}
