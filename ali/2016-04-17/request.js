function request(urls, callback) {
  let res = [];

  let requestIter = (urls, idx, res) => {
    if (urls.length == idx) {
      callback(res);
    } else {
      $.ajax({
        url: urls[idx],
        success: (data, status, xhr) => {
          res.push(data);
          requestIter(urls, idx + 1, res);
        },
        error: (data, status, error) => {
          callback(null);
        },
      });
    }
  };

  requestIter(urls, 0, res);
}