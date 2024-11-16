package main

import (
	"context"
	"fmt"
	pb "go-client-test/proto"
	"log"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

func main() {

	conn, err := grpc.NewClient("172.29.160.1:9002", grpc.WithTransportCredentials(insecure.NewCredentials()))
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()

	//建立连接
	client := pb.NewHelloGrpcClient(conn)

	//执行rpc调用
	resp, err := client.SayHello(context.Background(), &pb.HelloRequest{Name: "tianlong"})

	if err != nil {
		log.Fatalf("err: %v", err)
	}

	fmt.Printf("resp msg is: \"%s\"\n", resp.GetMessage())

}
