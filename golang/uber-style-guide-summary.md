- Ref
    - linters
        - https://github.com/kisielk/errcheck
        - https://godoc.org/golang.org/x/tools/cmd/goimports
        - https://github.com/golang/lint
        - https://golang.org/cmd/vet/
        - https://staticcheck.io/
        - https://github.com/golangci/golangci-lint
            - https://github.com/uber-go/guide/blob/master/.golangci.yml
            - https://golangci-lint.run/usage/linters/
    - https://dave.cheney.net/2016/04/27/dont-just-check-errors-handle-them-gracefully
    - https://cloud.google.com/functions/docs/bestpractices/tips#use_global_variables_to_reuse_objects_in_future_invocations
    - https://pkg.go.dev/go.uber.org/goleak
    - https://blog.golang.org/package-names
    - https://rakyll.org/style-packages/
    - https://golang.org/cmd/vet/#hdr-Printf_family
    - https://kuzminva.wordpress.com/2017/11/07/go-vet-printf-family-check/

- change
    ```
    type SMap struct {
        sync.Mutex
    }
    ```
    to
    ```
    type SMap struct {
        mu sync.Mutex
    }
    ```

- Copy Slices and Maps at Boundaries

- Defer to Clean Up
    ```
    p.Lock()
    defer p.Unlock()
    ```

- Channel Size is One or None

- Start Enums at One
    ```
    type Operation int

    const (
        Add Operation = iota + 1
        Subtract
        Multiply
    )
    ```

- Use "time" to handle time
    ```
    newDay := t.AddDate(0 /* years */, 0 /* months */, 1 /* days */)
    maybeNewDay := t.Add(24 * time.Hour)
    ```

    ```
    IntervalMillis int `json:"intervalMillis"`
    ```

- Errors

    | Error matching? | Error Message | Guidance |
    | :--- | :--- | :--- |
    | No | static | `errors.New` |
    | No | dynamic | `fmt.Errorf` |
    | Yes | static | top-level var with `errors.New` |
    | Yes | dynamic | custom error type |

    - change
        ```
        return fmt.Errorf("failed to create new store: %w", err)
        ```
        to
        ```
        return fmt.Errorf("new store: %w", err)
        ```

    - For error values stored as global variables, use the prefix `Err` or `err` depending on whether they're exported. This guidance supersedes the Prefix Unexported Globals with \_.

- Prefix Unexported Globals with \_
    - Exception: Unexported error values may use the prefix err without the underscore.

- Handle Type Assertion Failures
    ```
    t, ok := i.(string)
    if !ok {
        // handle the error gracefully
    }
    ```

- Don't Panic
    - Use Errors

- Use go.uber.org/atomic

- Avoid Mutable Globals

- Avoid Embedding Types in Public Structs

- Avoid Using Built-In Names

- Exit in Main
    - Go programs use `os.Exit` or `log.Fatal*` to exit immediately. (Panicking is not a good way to exit programs, please don't panic.)
    - Call one of `os.Exit` or `log.Fatal*` only in `main()`. All other functions should return errors to signal failure.
    - If possible, prefer to call `os.Exit` or `log.Fatal` at most once in your `main()`

- Use field tags in marshaled structs

- Don't fire-and-forget goroutines
    - do not leak goroutines in production code. Use go.uber.org/goleak to test for goroutine leaks inside packages that may spawn goroutines.
    - Wait for goroutines to exit
        - `sync.WaitGroup`
        - `chan struct{}`
    - worker go routines

- Prefer strconv over fmt
    - convert ```fmt.Sprint(rand.Int())``` to ```strconv.Itoa(rand.Int())```.
    - Avoid string-to-byte conversion

- Prefer Specifying Container Capacity

- Group Similar Declarations
    change
    ```
    type Area float64
    type Volume float64
    ```
    to
    ```
    type (
        Area float64
        Volume float64
    )
    ```
    - Only group related declarations. Do not group declarations that are unrelated.

- Function Grouping and Ordering
    - Functions should be sorted in rough call order.
    - Functions in a file should be grouped by receiver.
    - Therefore, exported functions should appear first in a file, after `struct`, `const`, `var` definitions.
    - A `newXYZ()/NewXYZ()` may appear after the type is defined, but before the rest of the methods on the receiver.
    - Since functions are grouped by receiver, plain utility functions should appear towards the end of the file.

- Embedding in Structs
    - Embedded types should be at the top of the field list of a struct, and there must be an empty line separating embedded fields from regular fields.

- Change
    ```
    filtered := []int{}
    ```
    to
    ```
    var filtered []int
    ```
    ```
    user := User{}
    ```
    to
    ```
    var user User
    ```

- Reduce Scope of Variables
    - If you need a result of a function call outside of the if, then you should not try to reduce the scope.

- Avoid Naked Parameters
    - ```printInfo("foo", true /* isLocal */, true /* done */)```
    - Better yet, replace naked bool types with custom types for more readable and type-safe code. This allows more than just two states (true/false) for that parameter in the future.

- Initializing Struct References
    - Use `&T{}` instead of `new(T)` when initializing struct references so that it is consistent with the struct initialization.

- ```const msg = "unexpected values %v, %v\n"```

- (TODO) Patterns

- id or ID

- Go interfaces generally belong in the package that uses values of the interface type, not the package that implements those values.

- Change
    ```
    func (f *Foo) Location() (float64, float64, error)
    ```
    to
    ```
    func (f *Foo) Location() (lat, long float64, err error)
    ```

- Variable Names
    - Prefer c to lineCount. Prefer i to sliceIndex.
