#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "./proto/hello.grpc.pb.h"

using grpc::Status;
using grpc::Channel;
using grpc::ServerContext;
using grpc::ServerBuilder;

class HelloServiceImpl final : public hello::HelloGrpc::Service {
    Status SayHello(ServerContext* context, const hello::HelloRequest* request,
        hello::HelloReply* reply) override {
        std::string prefix("cpp_server: hello ");
        reply->set_message(prefix + request->name());
        return Status::OK;
    }
};

static void RunServer() {
    std::string server_address("172.29.160.1:9002");
    HelloServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}