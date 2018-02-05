let option_map = (fn, value) =>
  switch value {
  | None => None
  | Some(value) => Some(fn(value))
  };
