const app = require("./src/app");

const PORT = 3055;

const server = app.listen(PORT, () => {
  console.log(`WSV Server is running on port ${PORT}`);
});


process.on("unhandledRejection", (err) => {
  console.error("Unhandled Rejection:", err);
  // Optionally, you can shut down the server gracefully
  server.close(() => {
    process.exit(1);
    app.notifyAdmin("Unhandled Rejection", err);
  });
});

// this scope mean that any unhandled promise rejections will be caught here