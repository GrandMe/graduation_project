package nxu.it;

import io.quarkus.grpc.GrpcService;

import io.smallrye.mutiny.Uni;

@GrpcService
public class HelloGrpcService implements HelloGrpc {

    @Override
    public Uni<HelloReply> sayHello(HelloRequest request) {
        return Uni.createFrom().item(() ->
                HelloReply.newBuilder().setMessage("java_server: hello " + request.getName()).build()
        );
    }

}