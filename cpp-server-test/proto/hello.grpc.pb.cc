// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/hello.proto

#include "hello.pb.h"
#include "hello.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace hello {

static const char* HelloGrpc_method_names[] = {
  "/hello.HelloGrpc/SayHello",
};

std::unique_ptr< HelloGrpc::Stub> HelloGrpc::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< HelloGrpc::Stub> stub(new HelloGrpc::Stub(channel, options));
  return stub;
}

HelloGrpc::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SayHello_(HelloGrpc_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status HelloGrpc::Stub::SayHello(::grpc::ClientContext* context, const ::hello::HelloRequest& request, ::hello::HelloReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::hello::HelloRequest, ::hello::HelloReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

void HelloGrpc::Stub::async::SayHello(::grpc::ClientContext* context, const ::hello::HelloRequest* request, ::hello::HelloReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::hello::HelloRequest, ::hello::HelloReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, std::move(f));
}

void HelloGrpc::Stub::async::SayHello(::grpc::ClientContext* context, const ::hello::HelloRequest* request, ::hello::HelloReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::hello::HelloReply>* HelloGrpc::Stub::PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::hello::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::hello::HelloReply, ::hello::HelloRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SayHello_, context, request);
}

::grpc::ClientAsyncResponseReader< ::hello::HelloReply>* HelloGrpc::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::hello::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSayHelloRaw(context, request, cq);
  result->StartCall();
  return result;
}

HelloGrpc::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HelloGrpc_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HelloGrpc::Service, ::hello::HelloRequest, ::hello::HelloReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HelloGrpc::Service* service,
             ::grpc::ServerContext* ctx,
             const ::hello::HelloRequest* req,
             ::hello::HelloReply* resp) {
               return service->SayHello(ctx, req, resp);
             }, this)));
}

HelloGrpc::Service::~Service() {
}

::grpc::Status HelloGrpc::Service::SayHello(::grpc::ServerContext* context, const ::hello::HelloRequest* request, ::hello::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace hello
