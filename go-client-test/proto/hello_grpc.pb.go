// Code generated by protoc-gen-go-grpc. DO NOT EDIT.
// versions:
// - protoc-gen-go-grpc v1.5.1
// - protoc             v5.29.0--rc1
// source: hello.proto

package pb

import (
	context "context"
	grpc "google.golang.org/grpc"
	codes "google.golang.org/grpc/codes"
	status "google.golang.org/grpc/status"
)

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
// Requires gRPC-Go v1.64.0 or later.
const _ = grpc.SupportPackageIsVersion9

const (
	HelloGrpc_SayHello_FullMethodName = "/hello.HelloGrpc/SayHello"
)

// HelloGrpcClient is the client API for HelloGrpc service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://pkg.go.dev/google.golang.org/grpc/?tab=doc#ClientConn.NewStream.
type HelloGrpcClient interface {
	SayHello(ctx context.Context, in *HelloRequest, opts ...grpc.CallOption) (*HelloReply, error)
}

type helloGrpcClient struct {
	cc grpc.ClientConnInterface
}

func NewHelloGrpcClient(cc grpc.ClientConnInterface) HelloGrpcClient {
	return &helloGrpcClient{cc}
}

func (c *helloGrpcClient) SayHello(ctx context.Context, in *HelloRequest, opts ...grpc.CallOption) (*HelloReply, error) {
	cOpts := append([]grpc.CallOption{grpc.StaticMethod()}, opts...)
	out := new(HelloReply)
	err := c.cc.Invoke(ctx, HelloGrpc_SayHello_FullMethodName, in, out, cOpts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// HelloGrpcServer is the server API for HelloGrpc service.
// All implementations must embed UnimplementedHelloGrpcServer
// for forward compatibility.
type HelloGrpcServer interface {
	SayHello(context.Context, *HelloRequest) (*HelloReply, error)
	mustEmbedUnimplementedHelloGrpcServer()
}

// UnimplementedHelloGrpcServer must be embedded to have
// forward compatible implementations.
//
// NOTE: this should be embedded by value instead of pointer to avoid a nil
// pointer dereference when methods are called.
type UnimplementedHelloGrpcServer struct{}

func (UnimplementedHelloGrpcServer) SayHello(context.Context, *HelloRequest) (*HelloReply, error) {
	return nil, status.Errorf(codes.Unimplemented, "method SayHello not implemented")
}
func (UnimplementedHelloGrpcServer) mustEmbedUnimplementedHelloGrpcServer() {}
func (UnimplementedHelloGrpcServer) testEmbeddedByValue()                   {}

// UnsafeHelloGrpcServer may be embedded to opt out of forward compatibility for this service.
// Use of this interface is not recommended, as added methods to HelloGrpcServer will
// result in compilation errors.
type UnsafeHelloGrpcServer interface {
	mustEmbedUnimplementedHelloGrpcServer()
}

func RegisterHelloGrpcServer(s grpc.ServiceRegistrar, srv HelloGrpcServer) {
	// If the following call pancis, it indicates UnimplementedHelloGrpcServer was
	// embedded by pointer and is nil.  This will cause panics if an
	// unimplemented method is ever invoked, so we test this at initialization
	// time to prevent it from happening at runtime later due to I/O.
	if t, ok := srv.(interface{ testEmbeddedByValue() }); ok {
		t.testEmbeddedByValue()
	}
	s.RegisterService(&HelloGrpc_ServiceDesc, srv)
}

func _HelloGrpc_SayHello_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(HelloRequest)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(HelloGrpcServer).SayHello(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: HelloGrpc_SayHello_FullMethodName,
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(HelloGrpcServer).SayHello(ctx, req.(*HelloRequest))
	}
	return interceptor(ctx, in, info, handler)
}

// HelloGrpc_ServiceDesc is the grpc.ServiceDesc for HelloGrpc service.
// It's only intended for direct use with grpc.RegisterService,
// and not to be introspected or modified (even as a copy)
var HelloGrpc_ServiceDesc = grpc.ServiceDesc{
	ServiceName: "hello.HelloGrpc",
	HandlerType: (*HelloGrpcServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "SayHello",
			Handler:    _HelloGrpc_SayHello_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "hello.proto",
}
