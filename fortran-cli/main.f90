program together_cli
  implicit none
  character(len=1024) :: prompt
  character(len=4096) :: command
  integer :: ios
  character(len=1024) :: apiKey
  character(len=1024) :: line
  integer :: unit, stat
  character(len=4096) :: escaped_prompt

  ! Check if prompt is provided as command line argument
  if (command_argument_count() < 1) then
    print *, "Please provide a prompt as a command line argument."
    stop 1
  endif

  call get_command_argument(1, prompt)

  ! Read API key from .env file in fortran-cli folder
  apiKey = ""
  open(newunit=unit, file='fortran-cli/.env', status='old', action='read', iostat=stat)
  if (stat /= 0) then
    print *, "Error: .env file not found."
    stop 1
  endif

  do
    read(unit, '(A)', iostat=stat) line
    if (stat /= 0) exit
    if (index(line, "TOGETHER_API_KEY=") == 1) then
      apiKey = adjustl(line(18:))  ! length of "TOGETHER_API_KEY=" is 17, so start from 18
      exit
    endif
  end do
  close(unit)

  if (len_trim(apiKey) == 0) then
    print *, "Error: TOGETHER_API_KEY not found in .env file."
    stop 1
  endif

  ! Escape double quotes and backslashes in prompt for JSON
  call escape_json_chars(trim(prompt), escaped_prompt)

  ! Construct curl command to call Together API
  write(command, '(A)') 'curl -s -X POST https://api.together.xyz/v1/chat/completions ' // &
       '-H "Authorization: Bearer ' // trim(apiKey) // '" ' // &
       '-H "Content-Type: application/json" ' // &
       '-d "{\"model\":\"nvidia/Llama-3.1-Nemotron-70B-Instruct-HF\",\"messages\":[{\"role\":\"user\",\"content\":\"' // trim(escaped_prompt) // '\"}]}"'

  ! Execute the command and capture the response
  call execute_command(command, ios)

contains

  subroutine execute_command(cmd, status)
    character(len=*), intent(in) :: cmd
    integer, intent(out) :: status
    integer :: ret

    ret = system(trim(cmd))
    status = ret
  end subroutine execute_command

  subroutine escape_json_chars(input, output)
    character(len=*), intent(in) :: input
    character(len=*), intent(out) :: output
    integer :: i, j, len_in
    character(len=1) :: c

    len_in = len_trim(input)
    j = 1
    do i = 1, len_in
      c = input(i:i)
      select case (c)
      case ('"')
        output(j:j+1) = '\\"'
        j = j + 2
      case ('\\')
        output(j:j+1) = '\\\\'
        j = j + 2
      case default
        output(j:j) = c
        j = j + 1
      end select
    end do
    output(j:) = ''
  end subroutine escape_json_chars

end program together_cli
