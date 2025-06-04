import scala.concurrent.Await
import scala.concurrent.duration.Duration
import sttp.client3._
import sttp.client3.asynchttpclient.future.AsyncHttpClientFutureBackend
import sttp.model.MediaType
import scala.concurrent.ExecutionContext.Implicits.global

object Main extends App {
  if (args.length == 0) {
    println("Please provide a prompt as a command line argument.")
    System.exit(1)
  }

  // Paste your API key here
  val apiKey = "<PASTE_YOUR_API_KEY_HERE>"

  val prompt = args.mkString(" ")

  implicit val backend: SttpBackend[scala.concurrent.Future, Any] = AsyncHttpClientFutureBackend()

  val requestBody =
    s"""
       |{
       |  "model": "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF",
       |  "messages": [
       |    {
       |      "role": "user",
       |      "content": "$prompt"
       |    }
       |  ]
       |}
       |""".stripMargin

  val request = basicRequest
    .post(uri"https://api.together.xyz/v1/chat/completions")
    .contentType(MediaType.ApplicationJson)
    .header("Authorization", s"Bearer $apiKey")
    .body(requestBody)

  val responseFuture = request.send()

  val response = Await.result(responseFuture, Duration.Inf)

  if (response.code.isSuccess) {
    println(response.body.getOrElse("No response body"))
  } else {
    println(s"Request failed with status code: ${response.code}")
    println(response.body.left.getOrElse("No error body"))
  }

  backend.close()
}
