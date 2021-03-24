#include <node.h>
#include "encrypt.h"
#include "decrypt.h"

namespace demo {

using v8::Local;
using v8::Object;

void InitAll(Local<Object> exports) {
  InitEncrypt(exports);
  InitDecrypt(exports);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)

} 