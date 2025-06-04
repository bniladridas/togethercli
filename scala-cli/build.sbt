ThisBuild / version := "0.1.0"
ThisBuild / scalaVersion := "2.13.12"

lazy val root = (project in file("."))
  .settings(
    name := "scala-cli",
    libraryDependencies ++= Seq(
      "com.softwaremill.sttp.client3" %% "core" % "3.9.0",
      "com.softwaremill.sttp.client3" %% "async-http-client-backend-future" % "3.9.0",
      "com.github.pureconfig" %% "pureconfig" % "0.17.4",
      "com.typesafe.play" %% "play-json" % "2.9.4"
    )
  )
