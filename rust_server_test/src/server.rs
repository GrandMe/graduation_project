use hello::hello_grpc_server::{HelloGrpc , HelloGrpcServer};
use hello::{HelloRequest , HelloReply};
use tonic::transport::Server;
use tonic::{Request, Response, Status};

pub mod hello {
    tonic::include_proto!("hello");
}

#[derive(Debug , Default)]
pub struct HelloService{}

#[tonic::async_trait]
impl HelloGrpc for HelloService {

    async fn say_hello(
        &self, 
        request: Request<HelloRequest>
    ) -> Result<Response<HelloReply>, Status> {

        // println!("{:#?}", request);

        let req = request.into_inner();
        let response = HelloReply {
            message: format!("rust_server: hello {}" , req.name),
        };

        Ok(Response::new(response))
    }
    
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>>{
    let addr = "127.0.0.1:9001".parse()?;
    let hello = HelloService::default();
    println!("HelloService listening on {}", addr);

    Server::builder()
        .add_service(HelloGrpcServer::new(hello))
        .serve(addr)
        .await?;

    Ok(())
}
